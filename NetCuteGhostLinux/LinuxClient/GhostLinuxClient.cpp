#include "GhostLinuxClient.h"
#include "LinuxUtilCustom.h"

#include <signal.h>



NetCuteGhostLinuxClient::NetCuteGhostLinuxClient
(
	std::string InLinuxServerIP,
	int InLinuxServerPort
)
: LinuxServerIP(InLinuxServerIP)
, LinuxServerPort(InLinuxServerPort)
, bToggleChat(false)
, bContinueLoop(true)
{
	InitClient();
	InitSignalHandler();
	MainLoop();
}

NetCuteGhostLinuxClient::~NetCuteGhostLinuxClient()
{
	std::cout << "CLIENT::PROCESS FINALIZE(PID) : " << getpid() << std::endl;
	close(LinuxServerSocket);
}





// Send function
void NetCuteGhostLinuxClient::Send(SOCKET SendSocket, std::string InString)
{
	strcpy(LinuxBuf, InString.c_str());
		
	int SuccessFlag = send(SendSocket, LinuxBuf, sizeof(LinuxBuf), 0);
	if(SuccessFlag == SOCKET_ERROR)
	{
		perror("send<Client> Error");
		close(LinuxServerSocket);
		exit(1);
	}
	else
	{
		std::cout << "send<Client> : " << LinuxBuf << std::endl;
	}
}

// Recv function
void NetCuteGhostLinuxClient::Recv(SOCKET RecvSocket, std::string& OutString)
{	
	int ReadFlag = recv(RecvSocket, LinuxBuf, sizeof(LinuxBuf), 0);
	if(ReadFlag == SOCKET_ERROR)
	{
		perror("recv<Client> Error");
		close(LinuxServerSocket);
		exit(1);
	}
	else if (ReadFlag == 0)
	{
		bContinueLoop = false;
	}
	else
	{
		std::cout << "recv<Client> : " << LinuxBuf << std::endl;
	}
	OutString = LinuxBuf;
}





// SIGINT Handler function
void NetCuteGhostLinuxClient::SigintHandler(int SignalNumber)
{
	psignal(SignalNumber, "Client will be pause after 1 sec");
	sleep(1);
	std::cout << "CLIENT::## Press Any Key to continue process ##" << std::endl;
	pause();
}

// SIGQUIT Handler function
void NetCuteGhostLinuxClient::SigquitHandler(int SignalNumber)
{
	psignal(SignalNumber, "Client will be quit after 3 sec");
	
	// block all signal
	sigset_t allblocksigset;
	sigfillset(&allblocksigset);
	sigprocmask(SIG_BLOCK, &allblocksigset, (sigset_t*)nullptr);
	
	// countdown for just visualize effect
	sleep(1);
	psignal(SignalNumber, "Client will be quit after 2 sec");
	sleep(1);
	psignal(SignalNumber, "Client will be quit after 1 sec");
	
	sleep(1);
	psignal(SignalNumber, "Client will be quit after 0 sec");
	
	std::exit(EXIT_SUCCESS);
}



// Init Overall Process
void NetCuteGhostLinuxClient::InitClient()
{
	memset(&LinuxBuf, 0, sizeof(LinuxBuf));
	memset(&LinuxSer, 0, sizeof(LinuxSer));
	LinuxSer.sin_family = AF_INET;
	LinuxSer.sin_port = htons(LinuxServerPort);
	LinuxSer.sin_addr.s_addr = inet_addr(LinuxServerIP.c_str());
	
	// LinuxServer Socket create using LinuxServer AddrIn
	if( (LinuxServerSocket = socket(AF_INET, SOCK_STREAM, 0)) == SOCKET_ERROR )
	{
		perror("socket");
		exit(1);
	}
	
	// Connect With LinuxServer Socket
 	if( connect(LinuxServerSocket, (struct sockaddr*)&LinuxSer, sizeof(LinuxSer)) < 0 )
	{
		perror("connect");
		close(LinuxServerSocket);
		exit(1);
	}
	
	std::cout << "CLIENT::CONNECT" << std::endl;
}

// Init Signal Handler
void NetCuteGhostLinuxClient::InitSignalHandler()
{	
	if( sigset(SIGINT, SigintHandler) == SIG_ERR )
	{
		perror("Sigset( SIGINT )");
		exit(1);
	}
	
	if( sigset(SIGQUIT, SigquitHandler) == SIG_ERR)
	{
		perror("Sigset( SIGQUIT )");
		exit(1);
	}
}



// Overall MainLoop
void NetCuteGhostLinuxClient::MainLoop()
{
	std::string struserinput;	
	char userchat[NET_MAXLEN];
	
	// MainLoop
	while( bContinueLoop == true )
	{
		// Current mode is game input mode
		if( bToggleChat == false)
		{
			struserinput = ProcessUserInput();
			if(struserinput.empty() == true)
			{
				continue;
			}
			
			Send(LinuxServerSocket, struserinput);
		}
		// Current mode is chat mode
		else
		{
			std::cout << "[[ TEXT ]] ";
			std::cin.getline(userchat, sizeof(userchat));

			std::string strChat;
			strChat = ProcessUserChatting(userchat);
			if(strChat.empty())
			{
				continue;
			}
			bToggleChat = false;
			
			Send(LinuxServerSocket, strChat.c_str());
			ProcessUserCmd(strChat);
		}
	}
}



// Process User Input
std::string NetCuteGhostLinuxClient::ProcessUserInput()
{
	int input;
	static std::string prevstr;
	std::string retstr;
	// maybe arrow input
	// maybe '\033'
	switch(input = getch())
	{
	// user press enter
	case 't':
	case 'T':
		bToggleChat = true;
		break;
	// user maybe press arrow input
	case '\033':
		getch();
		// maybe 'A', 'B', 'C', 'D'
		// or '1', '2', '3', '4'
		switch(input = getch())
		{
		case 'A':
			retstr = NetMessage::LnxClient::GAME::UP;
			break;
		case 'B':
			retstr = NetMessage::LnxClient::GAME::DOWN;
			break;
		case 'C':
			retstr = NetMessage::LnxClient::GAME::RIGHT;
			break;
		case 'D':
			retstr = NetMessage::LnxClient::GAME::LEFT;
			break;
		}
		break;
	// user maybe press slow movement input
	case ';':
		if( getch() == 50)
		{
			switch(input = getch())
			{
			case 'A':
				retstr = NetMessage::LnxClient::GAME::SLOWUP;
				break;
			case 'B':
				retstr = NetMessage::LnxClient::GAME::SLOWDOWN;
				break;
			case 'C':
				retstr = NetMessage::LnxClient::GAME::SLOWRIGHT;
				break;
			case 'D':
				retstr = NetMessage::LnxClient::GAME::SLOWLEFT;
				break;
			}
		}
		break;
	// user maybe press stop key
	case 'v':
	case 'V':
		retstr = NetMessage::LnxClient::GAME::STOP;
		break;
	default:
		retstr = static_cast<char>(input);
		break;
	}
	
	prevstr = retstr;
	return retstr;
}

// Process User Chatting
std::string NetCuteGhostLinuxClient::ProcessUserChatting(std::string inChat)
{
	// Check Chatting is valid
	if (inChat.empty())
	{
		return std::string();
	}
	if (inChat.size() > NET_MAXLEN)
	{
		std::cout << "CLIENT::!! Too many characters are in TEXT. MAX Number of Chracters : " << NET_MAXLEN << std::endl;
		return std::string();
	}
	
	
	std::string retstr;
	// If chatting is sooooo loooong, input chatting is cut by std::string
	retstr = retstr + (NetMeta::CHATTING) + " ";
	retstr.append(inChat); 
	
	return retstr;
}

// Process User Command
void NetCuteGhostLinuxClient::ProcessUserCmd(std::string InUserChat)
{
	std::string retstr;
	if( strncmp(InUserChat.c_str(), "#", 1) != 0 )
	{
		return;
	}
	
	if( strcmp(InUserChat.c_str(), NetMessage::LnxClient::CMD::QUIT.c_str()) == 0)
	{
		std::cout << "SYSTEM::## Client will be quit" << std::endl;
		std::cout << "SYSTEM::## waiting for shutdown" << std::endl;
		sleep(3);
		
		bContinueLoop = false;
	}
}