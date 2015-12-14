/* 89-210-04 210028924 Yossi Silberhaft*/
/****************************************
 * Yossi Silberhaft						*
 * Exercise 4							*
 * File: main.cpp						*
 ****************************************/
#include <list>
#include <iostream>
#include "Cinema.h"
#include "UDPServer.h"

using namespace std;

#define IP_ADDRESS "127.0.0.1"
#define SERVER_PORT 5678

/************************************************************************
* 								*
 ************************************************************************/
int main(int argc, char **argv){
	cout << "Starting Program" << endl;
	//Gets the type and port number from giver parameters
	//string type = argv[1];
	//string port = argv[2];
	//TODO remove the outputs below
	//cout << "Type: " << type << endl;
	//cout << "Port: " << port << endl;


	char data[] = "Do you want to build a snowman?";
	//the size of string
	int data_len = sizeof(data);

	UDPServer* server = new UDPServer;

	server->newSocket(SOCK_DGRAM);
	server->bindUDP(SERVER_PORT);
	server->receiveFrom();


	cout << "HERE" << endl;


	Cinema cinema;
	cinema.runCinema();
	return 0;


}
