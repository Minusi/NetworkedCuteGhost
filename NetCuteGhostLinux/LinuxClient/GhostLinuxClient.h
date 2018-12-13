#pragma once

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <string>
#include <cstdlib>

#include "NetMessages.h"




class NetCuteGhostLinuxClient
{
	#define SOCKET_ERROR -1
	typedef int SOCKET;
	
public:
	// NetCuteGhostLinuxServer Constructor
	NetCuteGhostLinuxClient
	(
		std::string InLinuxServerIP = "192.168.43.15",
		int InLinuxServerPort = 4315
	);
	
	// NetCuteGhostLinuxSErver Constructor
	~NetCuteGhostLinuxClient();	
	
	
	
	// Send function
	void Send(SOCKET SendSocket, std::string InString);
	
	// Recv function
	void Recv(SOCKET RecvSocket, std::string& OutString);
	
	
	
private:
	// SIGINT Handler function
	static void SigintHandler(int SignalNumber);
	
	// SIGQUIT Handler function
	static void SigquitHandler(int SignalNumber);



	// Init Overall Process
	void InitClient();

	// Init Signal Handler
	void InitSignalHandler();
	
	// Overall MainLoop
	void MainLoop();
	
	// Process User Input
	std::string ProcessUserInput();
	
	// Process User Chatting
	std::string ProcessUserChatting(std::string inChat);

	// Process User Command
	void ProcessUserCmd(std::string InUserChat);


private:
	// linux server socket for connect linux server 
	SOCKET LinuxServerSocket;
	struct sockaddr_in LinuxSer;

	// linux buffer for linux client
	char LinuxBuf[BUFSIZE];
	
	// linux server information for accept linux client
	std::string LinuxServerIP;
	int LinuxServerPort;
	
	
	
	// Toggle Chat Mode, if true, Chat Mode Activated
	bool bToggleChat;
	bool bContinueLoop;
};

