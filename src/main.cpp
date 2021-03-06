/* 89-210-04 210028924 Yossi Silberhaft*/
/*89-210-04 204256416 Nava Shemoul*/

/****************************************
 * Yossi Silberhaft & Nava Shemoul		*
 * Exercise 4							*
 * File: main.cpp						*
 ****************************************/
#include <list>
#include <iostream>
#include "Cinema.h"

using namespace std;

/************************************************************************
* This is the main function of the program that will create a			*
 * new Cinema. It will then pass the given arguments of Server/Client	*
 * type and port number to the run function								*
 ************************************************************************/
int main(int argc, char **argv){
	//Gets the Server/Client type and port number from Arguments
	int port = atoi(argv[2]);
	int type = atoi(argv[1]);
	Cinema cinema;
	cinema.runCinema(type, port);

	return 0;
}
