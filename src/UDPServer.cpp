/****************************************
 * Yossi Silberhaft & Nava Shemoul						*
 * Exercise 4							*
 * File: UDPServer.cpp     				*
 ****************************************/
#include <netinet/in.h>
#include <stdio.h>
#include "UDPServer.h"


/************************************************************************
* This is the UDPServer Class constructor		  					    *
************************************************************************/
UDPServer::UDPServer() { }


/************************************************************************
* This is the UDPServer Class destructor        					    *
************************************************************************/
UDPServer::~UDPServer() { }


/************************************************************************
* This function binds the socket with the designated port number        *
************************************************************************/
void UDPServer::bindUDP(unsigned short int server_port) {
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));

    //ipv4 socket address structure
    sin.sin_family = AF_INET;

    //binds to all ip address of the host
    sin.sin_addr.s_addr = INADDR_ANY;

    //convert byte order from host’s to network’s
    sin.sin_port = htons(server_port);

    //binds a socket to a port number
    if (bind(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error binding to socket\n");
    }
}