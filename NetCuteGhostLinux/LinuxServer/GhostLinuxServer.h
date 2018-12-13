#pragma once

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <wait.h>

#include <sys/msg.h>

#include <string>
#include <thread>
#include <memory>
#include <map>
#include <fstream>

#include "LinuxClient/NetMessages.h"



class NetCuteGhostLinuxServer
{
	#define SOCKET_ERROR -1
	typedef int SOCKET;
	typedef NetMessage::LnxServer::MessageBuf sMessageBuf;

public:
	// NetCuteGhostLinuxServer Constructor
	NetCuteGhostLinuxServer
	(
		std::string InGameIP = "192.168.43.170", 
		int InGamePort = 12357,
		std::string InLinuxIP = "192.168.43.15",
		int InLinuxPort = 4315
	);
	
	// NetCuteGhostLinuxSErver Constructor
	~NetCuteGhostLinuxServer();	
	
	
	
	// Send function
	bool Send(SOCKET SendSocket, std::string InString);
	
	// Recv function
	bool Recv(SOCKET RecvSocket, std::string& OutString);
	
	
	
private:
	// Init Overall Process
	void Init();
	
	// Initialize Server
	void InitServer();

	// Initialize Message Queue
	bool InitMessageQueue();
	
	// Initialize File System
	bool InitFileSystem();

	// Main Process of Linux Server
	void LinuxMainLoop();
	
	// Accept for connect Client
	bool AcceptServer();



	// Initialize Client Socket;
	void InitProxy();
	
	// Main Process of Game Client
	void GameMainLoop();


	
	// Send Player Index to Child Process using Message Queue
	bool NotifyIndexToChild(const int index, const pid_t inpid);
	
	// Parse Received Buffer from Client
	bool ProcessClientBuf(sMessageBuf& OutBuf);

	// Check Message struct And Send to Message Queue
	bool ProcessMsgbufInChild(const sMessageBuf& InMsg);
	
	// Receive MessageBuf and Check, if not valid, instantly return
	bool CheckReceivedMsgbufInThread();

	// Log Chatting Content to file using File System
	bool LogChattingToFile(int PlayerIndex, std::string InString);

	
	
private:
	// game socket for connect game server 
	SOCKET GameServerSocket;
	struct sockaddr_in GameSer;

	// game buffer for windows game server
	char GameBuf[BUFSIZE];
	
	// game server information for connect windows game server
	std::string GameServerIP;
	int GameServerPort;
	
	
	
	// linux socket for listen client
	SOCKET ListenSocket;
	struct sockaddr_in LinuxSer;
	
	// linux socket for accept client
	SOCKET ConnectSocket;
	struct sockaddr_in LinuxCli;
		
	// linux buffer for linux client
	char LinuxBuf[BUFSIZE];
	std::string BufString;
	bool bSendingGame;
	bool bSendingClient;
	
	// linux server information for accept linux client
	std::string LinuxServerIP;
	int LinuxServerPort;
	
	
	
	// pidtable for identify each clients
	std::map<int, pid_t> pidtable;
	
	// variable for using message queue
	key_t MsgKey;
	int MsgId;
	
	key_t RcvKey;
	int RcvMsgId;
	
	// thread for linux client socket listening
	std::unique_ptr<std::thread> ServerThread;
	
	
	
	// OutputFile to write chat log
	std::ofstream OutputFile;
};