#include "GhostLinuxServer.h"
#include <iostream>
#include <memory>



int main(int argc, char **argv)
{
	std::string inputip;
	int inputport;
	std::cout << "SYSTEM::Input IP = ";
	std::cin >> inputip;
	
	std::cout << "SYSTEM::Input PORT = ";
	std::cin >> inputport;
	
	std::unique_ptr<NetCuteGhostLinuxServer> Server;
	if(inputip == "0" && inputport == 0)
	{
		Server.reset(new NetCuteGhostLinuxServer());
	}
	else
	{
		Server.reset(new NetCuteGhostLinuxServer(inputip, inputport));		
	}

	std::cout << "SYSTEM::END APPLICATION" << std::endl;
	return 0;
}
