#include <iostream>
#include <memory>

#include "GhostLinuxClient.h"
#include "LinuxUtilCustom.h"

int main(int argc, char **argv)
{
	std::string inputip;
	int inputport;
	std::cout << "CLIENT::Input Proxy IP = ";
	std::cin >> inputip;
	
	std::cout << "CLIENT::Input Proxy PORT = ";
	std::cin >> inputport;
		
	std::unique_ptr<NetCuteGhostLinuxClient> Client;
	if(inputip == "0" && inputport == 0)
	{
		Client.reset(new NetCuteGhostLinuxClient());
	}
	else{
		Client.reset(new NetCuteGhostLinuxClient(inputip, inputport));
	}
	return 0;
}
