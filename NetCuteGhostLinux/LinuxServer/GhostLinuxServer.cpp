#include "GhostLinuxServer.h"



NetCuteGhostLinuxServer::NetCuteGhostLinuxServer
(
	std::string InGameIP, 
	int InGamePort,
	std::string InLinuxIP,
	int InLinuxPort
)
: GameServerIP(InGameIP)
, GameServerPort(InGamePort)
, LinuxServerIP(InLinuxIP)
, LinuxServerPort(InLinuxPort)
{
	Init();
};

NetCuteGhostLinuxServer::~NetCuteGhostLinuxServer()
{
	std::cout << "SERVER::Process finalize, pid(" << getpid() << ")" << std::endl;
	close(GameServerSocket);
	close(ListenSocket);
	close(ConnectSocket);
}



// Send Function
bool NetCuteGhostLinuxServer::Send(SOCKET SendSocket, std::string InString)
{
	// Process When socket is GameServerSocket
	if(SendSocket == GameServerSocket)
	{
		strcpy(GameBuf, InString.c_str());

		int SuccessFlag = send(GameServerSocket, GameBuf, sizeof(GameBuf), 0);
		if(SuccessFlag == SOCKET_ERROR)
		{
			perror("Send<Game> Error");
			return false;
		}
		
		std::cout << "send<game> : " << GameBuf << std::endl;
	}
	// Process When socket is ConnectSocket
	else if(SendSocket == ConnectSocket)
	{
		int SuccessFlag = send(SendSocket, LinuxBuf, sizeof(LinuxBuf), 0);
		if(SuccessFlag == SOCKET_ERROR)
		{
			perror("Send<Linux> Error");
			return false;
		}
		
		std::cout << "send<linux> : " << GameBuf << std::endl;
	}
	
	return true;
}

// Recv Function
bool NetCuteGhostLinuxServer::Recv(SOCKET RecvSocket, std::string& OutString)
{
	// Process When socket is GameServerSocket
	if(RecvSocket == GameServerSocket)
	{		
		int ReadFlag = recv(RecvSocket, GameBuf, sizeof(GameBuf), 0);
		if(ReadFlag == SOCKET_ERROR)
		{
			perror("Recv<Game> Error");
			return false;
		}
		
		std::cout << "recv<game> : " << GameBuf << std::endl;
		OutString = GameBuf;
	}
	// Process When socket is ConnectSocket
	else if(RecvSocket == ConnectSocket)
	{
		int ReadFlag = recv(RecvSocket, LinuxBuf, sizeof(LinuxBuf), 0);
		if(ReadFlag == SOCKET_ERROR)
		{
			perror("Recv<Linux> Error");
			return false;
		}
		else if(ReadFlag == 0)
		{
			std::cout << "SERVER::CHILD::ClientSocket is closed" << std::endl;
			return  false;
		}

		std::cout << "recv<linux> : " << LinuxBuf << std::endl;
		OutString = LinuxBuf;
	}
	
	return true;
}





// Init Overall Process
void NetCuteGhostLinuxServer::Init()
{
	// set memory zero 
	memset(&GameBuf, 0, sizeof(GameBuf));
	memset(&LinuxBuf, 0, sizeof(LinuxBuf));

	// create key for efficient working
	MsgKey = ftok("/home/minusi/Desktop", 'P');
	RcvKey = ftok("/home/minusi/Desktop", 'C');

	// Init Linux Socket for using Server
	InitServer();
}

// Initialize Server
void NetCuteGhostLinuxServer::InitServer()
{
	// Create Socket For Listen Client
	if ((ListenSocket = socket(AF_INET, SOCK_STREAM, 0)) == SOCKET_ERROR)
	{
		perror("socket");
		exit(1);
	}


	// Set addr_in For Listen Client
	memset((char*)&LinuxSer, 0, sizeof(LinuxSer));
	LinuxSer.sin_family = AF_INET;
	LinuxSer.sin_port = htons(LinuxServerPort);
	LinuxSer.sin_addr.s_addr = inet_addr(LinuxServerIP.c_str());
	
	// Bind sockaddr to Server Socket
	if( bind(ListenSocket, (struct sockaddr*)&LinuxSer, sizeof(LinuxSer)) )
	{
		perror("bind");
		exit(1);
	}
	
	// Listen to connect with client
	if( listen(ListenSocket, MAX_LISTEN) )
	{
		perror("listen");
		close(ListenSocket);
		exit(1);
	}
	
	std::cout << "SERVER::<< Socket Network System is created >>" << std::endl;
	// Enter Linux Loop;
	LinuxMainLoop();
}

// Initialize Message Queue
bool NetCuteGhostLinuxServer::InitMessageQueue()
{
	int resctl = msgctl(MsgId, IPC_RMID, (struct msqid_ds*)NULL);
	if (resctl == -1)
	{
		std::cout << "Message Queue System is already clean" << std::endl;
	}
	resctl = msgctl(RcvMsgId, IPC_RMID, (struct msqid_ds*)NULL);
	if (resctl == -1)
	{
		std::cout << "Message Queue System is already clean" << std::endl;
	}
	
	MsgId = msgget(MsgKey, IPC_CREAT|0644);
	if (MsgId == -1)
	{
		perror("msgget<PARENT>");
		return false;
	}
	RcvMsgId = msgget(RcvKey, IPC_CREAT|0644);
	if (RcvMsgId == -1)
	{
		perror("msgget<CHILD>");
		return false;
	}
	
	std::cout << "SERVER::<< Message Queue System is created >>" << std::endl;
	std::cout << "SERVER::<< MsgId : " << MsgId << ", RcvMsgId : " << RcvMsgId << " >>" << std::endl;
	return true;
}

// Initialize File System
bool NetCuteGhostLinuxServer::InitFileSystem()
{
	OutputFile = std::ofstream("Chatlog.txt", std::ios::app);
	
	std::cout << "SERVER::<< File System is created >>" << std::endl;
	return true;
}



// Accept for connect Client
bool NetCuteGhostLinuxServer::AcceptServer()
{
	int clientlen = sizeof(LinuxCli); 
	// Accept Client
	if( (ConnectSocket = accept(ListenSocket, (struct sockaddr*)&LinuxCli, (socklen_t*)&clientlen)) == SOCKET_ERROR )
	{
		perror("accept");
		return false;
	}
	
	return true;
}

// Main Process of Linux Server
void NetCuteGhostLinuxServer::LinuxMainLoop()
{
	pid_t pid;
	memset(&pid, 0, sizeof(pid) * MAX_LISTEN);
	
	bool bContinue = true;			// if true, outmost loop will cycle
	bool bStayWhile = true;			// if false, return this function now, like rocket.
	while (bContinue == true)
	{
		std::cout << "SERVER::## Waiting for Client..." << std::endl;
		// Accept for Connect with Client
		bStayWhile = AcceptServer();
		if (bStayWhile == false)
		{
			return;
		}
		
		pid = fork();
		// Parent Process is doing Something
		if(pid > 0)
		{
			std::cout << "DEBUG::@@ Parent PID(" << getpid() << ") __" << __LINE__ << "__"
			<< __func__ << std::endl;
			// if thread is empty, then create Proxy thread
			if(ServerThread == nullptr)
			{
				// Init message queue
				bStayWhile = InitMessageQueue();
				bStayWhile = InitFileSystem();
				if (bStayWhile == false)
				{
					std::cout << "PRPROC::!! Message Queue System Init Failed !!" << std::endl;
					return;
				}
				
				// Make Proxy Thread 
				ServerThread = std::unique_ptr<std::thread>(new std::thread(&NetCuteGhostLinuxServer::InitProxy, this));		
				if(ServerThread == nullptr)
				{
					perror("serverthread");
					return;
				}
			}


		
			// Check if set size is over MAX_LISTEN
			// if over, something is wrong...
			if (pidtable.size() < MAX_LISTEN)
			{
				std::cout << std::endl << "## " << getpid() << " ##";
				for(int i = 0; i < MAX_LISTEN; ++i)
				{
					auto it = pidtable.find(i);
					if( it != pidtable.end())
					{
						std::cout << "DEBUG::## MAP[" << i << "] \t" << it->second << std::endl;
					}
				}
				std::cout << std::endl;
				
				int i;
				for(i = 0 ; i < MAX_LISTEN; ++i)
				{
					// find empty space for assign player index;
					auto it = pidtable.find(i);
					if (it == pidtable.end())
					{
						std::cout << "DEBUG::## MAP[" << i << "] is empty" << std::endl;
						pidtable.insert(std::make_pair(i, pid));
						break;
					}
					
					// check if pid still valid
					int status = 0;
					pid_t respid = waitpid(it->second, &status, WNOHANG);
					if (respid == -1)
					{
						// pid is not valid now, so erase, insert, and break
						std::cout << "DEBUG::## MAP["  << i << "]." << it->second 
						<< " is not valid" << std::endl;
						pidtable.erase(i);
						pidtable.insert(std::make_pair(i, pid));
						break;
					}
				} // END OF FOR STATEMENT
				
				// Send Message To Child Process
				NotifyIndexToChild(i, pid);
				
				
			} // END OF pidtable SIZE IF STATEMENT
			else
			{
				std::cout << "SERVER::!! PidTable is over than " << MAX_LISTEN << std::endl;
			}
		}
		// Child Process is doing Something
		// Child Process must be exit in this block
		else if(pid == 0)
		{
			// Child Process does not need ListenSocket and GameSocket
			close(ListenSocket);
			close(GameServerSocket);
			
			// Print to Check PID
			std::cout << std::endl << "CHPROC::## Child PID[" << getpid() << "]" << std::endl;

			// Init Exist Message Queue
			MsgId = msgget(MsgKey, 0);
			if(RcvMsgId == -1)
			{
				perror("msgget");
				return;
			}
			RcvMsgId = msgget(RcvKey, 0);
			if(RcvMsgId == -1)
			{
				perror("msgget");
				return;
			}
			
			
			sMessageBuf MsgBuf;
			memset(&MsgBuf.content, 0, sizeof(MsgBuf.content));

			// Receive Message from Parent Process
			msgrcv(RcvMsgId, (void*)&MsgBuf, sizeof(MsgBuf) - sizeof(long), getpid(), 0);
			if(strcmp(MsgBuf.content, NetMessage::LnxServer::IPC::INDEX.c_str()) != 0)
			{
				std::cout << "CHEROR::MessageBuf.content is not on purpose" << std::endl;
				return;
			}
			
			// Dummy Variable for use later?
			// int PlayerIndex = MsgBuf.index;
			
			
			/////////////////////////////////////////////////////////////////////////////////////////
			// Child Process MainLoop Control Flag
			bool bContinueChild = true;
			while (bContinueChild == true)
			{
				bContinueChild &= Recv(ConnectSocket, BufString);
				bContinueChild &= ProcessClientBuf(MsgBuf);

				bContinueChild &= ProcessMsgbufInChild(MsgBuf);
				
			}
			/////////////////////////////////////////////////////////////////////////////////////////

			std::cout << "CHPROC::<< Child Process Exit [" << getpid() << "] >>" << std::endl;
			// Escape child process mainloop
			// It means child process will be exited
			std::exit(EXIT_SUCCESS);
		}
		// Fork error case
		else
		{
			perror("fork");
			return;
		}
		
		// Child Process connect with client, so we need to clear this ConnectSocket
		close(ConnectSocket);
		
	} // END of Main Loop
	
	// One time Thread Join
	// Server waits until proxy thread exit
	bool bAlreadyJoin = false;
	if(bAlreadyJoin == false)
	{
		if(ServerThread->joinable())
		{
			std::cout << "SERVER::## Thread will be join in main" << std::endl;
			ServerThread->join();
		}
		bAlreadyJoin = true;
	}	

	// Server waits until all of child process exit
	pid_t wpid;
	int status = 0;
	while( (wpid = wait(&status)) > 0 );
	std::cout << "__END__" << std::endl;
	
}





// Initialize Client Socket
void NetCuteGhostLinuxServer::InitProxy()
{		
	// Create Socket For Connect Linux Server 
	if( (GameServerSocket = socket(AF_INET, SOCK_STREAM, 0)) == SOCKET_ERROR )
	{
		perror("socket");
		exit(1);
	}
	std::cout << "THREAD::SOCKET created" << std::endl;
	
	// set addr_in for connect Linux Server
	memset((char*)&GameSer, '\0', sizeof(GameSer));
	GameSer.sin_family = AF_INET;
	GameSer.sin_port = htons(GameServerPort);
	GameSer.sin_addr.s_addr = inet_addr(GameServerIP.c_str());
	
	// Connect with Server
	if( connect(GameServerSocket, (struct sockaddr*)&GameSer, sizeof(GameSer)) < 0 )
	{
		perror("connect");
		exit(1);
	}
	std::cout << "THREAD::Connect Successful" << std::endl;
	
	// Enter Main Loop
	GameMainLoop();
}

// Main Process of Game Client
void NetCuteGhostLinuxServer::GameMainLoop()
{
	/////////////////////////////////////////////////////////////////////////////////////////
	// Main Loop Control Flag
	bool bContinue = true;
	while (bContinue == true)
	{	
		bContinue &= CheckReceivedMsgbufInThread();
	}
	/////////////////////////////////////////////////////////////////////////////////////////
	
	
	// Cleanup Message Queue System
	int resctl = msgctl(MsgId, IPC_RMID, (struct msqid_ds*)NULL);
	if (resctl == -1)
	{
		perror("msgctl");
		return;
	}
	std::cout << "THREAD::<< Cleanup Message Queue System" << std::endl;
} 





bool NetCuteGhostLinuxServer::NotifyIndexToChild(const int index, const pid_t inpid)
{
	// Create and Fill Message
	sMessageBuf IndexMsgBuf;
	IndexMsgBuf.mtype = inpid;
	IndexMsgBuf.index = index;
	strcpy(IndexMsgBuf.content, NetMessage::LnxServer::IPC::INDEX.c_str());
	
	// Send Message To Child Process
	int sndlen = msgsnd(RcvMsgId, (void*)&IndexMsgBuf, sizeof(IndexMsgBuf) - sizeof(long), IPC_NOWAIT);
	if (sndlen == -1)
	{
		perror("msgsnd");
		return false;
	}
	return true;
}



// Parse Buf from Client sending
bool NetCuteGhostLinuxServer::ProcessClientBuf(sMessageBuf& OutBuf)
{
	// Check String validity
	if(BufString.size() == 0)
	{
		std::cout << "CHPROC::!! 0 byte Strings IN" << std::endl;
		return true;
	}
	
	
	// CMD Process Block
	if(strncmp(BufString.c_str(), "#", 1) == 0)
	{
		if(strcmp(BufString.c_str(), "#quit") == 0)
		{
			std::cout << "SYSTEM::Client will be quit" << std::endl;
			std::cout << "SYSTEM::waiting for shutdown ... 3 seconds" << std::endl;
			sleep(3);
			return false;
		}		
	}
	// GAME INPUT Process Block
	else if(strncmp(BufString.c_str(), "%", 1) == 0)
	{
		// Check string size in Buffer
		if( BufString.size() > sizeof(OutBuf.content) )
		{
			std::cout << "CHEROR::!! Buffer contents is bigger than OutBuf contents __" << __func__ << " !!" << std::endl;
			return false;
		}
		
		// Copy information to MessageBuf for send to Message Queue
		// This process does not include sMessageBuf.index
		OutBuf.mtype = getpid();
		strcpy(OutBuf.content, BufString.c_str());
	}
	// Chatting Process Block
	else if(strncmp(BufString.c_str(), "~", 1) == 0)
	{
		// Check string size in Buffer
		if( BufString.size() > sizeof(OutBuf.content) )
		{
			std::cout << "CERROR::!! Buffer contents is bigger than OutBuf contents __" << __func__ << " !!" << std::endl;
			return false;
		}
		
		// Copy information to MessageBuf for send to Message Queue
		// This process does not include sMessageBuf.index
		OutBuf.mtype = getpid();
		strcpy(OutBuf.content, BufString.c_str());	
	}
	else
	{
		OutBuf.mtype = -1;
	}
	
	return true;
}

bool NetCuteGhostLinuxServer::ProcessMsgbufInChild(const sMessageBuf& InMsg)
{
	// Check Message's index validity
	if (InMsg.index < 0 || InMsg.index > MAX_LISTEN)
	{
		return true;
	}

	// Check Message's content
	if (strlen(InMsg.content) == 0)
	{
		std::cout << "CHPROC::!! MessageBuf.content is empty" << std::endl;
		return true;
	}
	
	// Check Message's pid valid
	if(InMsg.mtype != getpid())
	{
		std::cout << "CHPROC::!! MessageBuf.mtype(" << InMsg.mtype 
		<< ") is not valid(" << getpid() <<")" << std::endl;
		return true;
	}
		
	// Send To Message Queue
	int resultsnd;
	resultsnd = msgsnd(MsgId, (void*)&InMsg, sizeof(InMsg) - sizeof(long), IPC_NOWAIT);
	if (resultsnd == -1)
	{
		perror("msgsnd");
		std::cout << "CHEROR::MsgId : " << MsgId << ", InMsg.mtype : " << InMsg.mtype << std::endl;
		return true;
	}
	std::cout << "msgsnd<MsgBuf> : mtype : " << InMsg.mtype << ", index : " << InMsg.index << ", content : " << InMsg.content << std::endl;

	return true;
}




bool NetCuteGhostLinuxServer::CheckReceivedMsgbufInThread()
{
	int msglen;
	sMessageBuf InMsg;

	// Continuosly read from message queue to pass message to game server.
	msglen = msgrcv(MsgId, (void*)&InMsg, sizeof(InMsg) - sizeof(long), 0, 0);
	if (msglen == -1)
	{
		std::cout << "THREAD::MSGRCV" << std::endl;
		return true;
	}
	std::cout << "msgrcv<MsgBuf> : mtype : " << InMsg.mtype << ", index : "  << InMsg.index << ", content : "
	<< InMsg.content << std::endl;


	// Check Message Content is empty
	if(strlen(InMsg.content) == 0)
	{
		std::cout << "THREAD::!! MessageBuf.content is empty" << std::endl;
		return true;
	}
	
	// Check Index - PID Connection is valid
	auto it = pidtable.find(InMsg.index);
	if (it == pidtable.end())
	{
		std::cout << "THREAD::!! MessageBuf.index(" << InMsg.index << ") is not valid" << std::endl;
		return true;
	}
	
	// Create GamePacket
	std::string packet;
	packet += std::to_string(InMsg.index);
	packet += ",";
	packet += InMsg.content;
	
	// Check Contents are chatting to log chatting file
	if(InMsg.content[0] == '~' || InMsg.content[1] == '~')
	{
		LogChattingToFile(InMsg.index, InMsg.content);
	}
	
	Send(GameServerSocket, packet);
	return true;
}

// Log Chatting Content to file using File System
bool NetCuteGhostLinuxServer::LogChattingToFile(int PlayerIndex, std::string InString)
{
	if (OutputFile.is_open())
	{
		OutputFile << "[" << PlayerIndex << " Player ] " << InString << std::endl;
	}
	else
	{
		std::cout << "THREAD::!! OutputFile cannot open" << std::endl;
	}
	
	return true;
}