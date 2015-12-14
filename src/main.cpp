/* 89-210-04 210028924 Yossi Silberhaft*/
/****************************************
 * Yossi Silberhaft						*
 * Exercise 4							*
 * File: main.cpp						*
 ****************************************/
#include <list>
#include <iostream>
#include "Cinema.h"

using namespace std;



/************************************************************************
* 								*
 ************************************************************************/
int main(int argc, char **argv){
	//Gets the type and port number from giver parameters
	string type = argv[1];
	string port = argv[2];
	//TODO remove the outputs below
	cout << "Type: " << type << endl;
	cout << "Port: " << port << endl;

	Cinema cinema;
	cinema.runCinema();
	return 0;


}
