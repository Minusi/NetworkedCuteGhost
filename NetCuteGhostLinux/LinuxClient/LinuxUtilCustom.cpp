#include "LinuxUtilCustom.h"
#include <unistd.h>
#include <termios.h>
#include <stdio.h>


char getch()
{
	struct termios oldt, newt;
	int ch;
	
	tcgetattr( STDIN_FILENO, &oldt );
	newt = oldt;
	newt.c_lflag &= ~( ICANON | ECHO );
	tcsetattr( STDIN_FILENO, TCSANOW, &newt );
	ch = getchar();
	tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
	return ch;
}