#include "GhostLinuxServer.h"
#include <iostream>
#include <memory>



int main(int argc, char **argv)
{
	std::string linuxinputip, gameinputip;
	int linuxinputport, gameinputport;

	std::cout << "SYSTEM::Input Game IP = ";
	std::cin >> gameinputip;
	
	std::cout << "SYSTEM::Input Game PORT = ";
	std::cin >> gameinputport;


	std::cout << "SYSTEM::Input Proxy IP = ";
	std::cin >> linuxinputip;
	
	std::cout << "SYSTEM::Input Proxy PORT = ";
	std::cin >> linuxinputport;	
	
	std::unique_ptr<NetCuteGhostLinuxServer> Server;
	if(gameinputip == "0" && gameinputport == 0
		&& linuxinputip == "0" && linuxinputport == 0)
	{
		Server.reset(new NetCuteGhostLinuxServer());
	}
	else
	{
		Server.reset(new NetCuteGhostLinuxServer(gameinputip, gameinputport, linuxinputip, linuxinputport));		
	}

	std::cout << "SYSTEM::END APPLICATION" << std::endl;
	return 0;
}
