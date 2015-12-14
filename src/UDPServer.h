/****************************************
 * Yossi Silberhaft						*
 * Exercise 4							*
 * File: UDPServer.h       				*
 ****************************************/
#ifndef UDPSERVER_H
#define UDPSERVER_H
#include "UDP.h"

class UDPServer: public UDP {

public:

    /************************************************************************
	 * This is the UDPServer Class constructor		        				*
	 ************************************************************************/
    UDPServer();


    /************************************************************************
	 * This is the UDPServer Class destructor                               *
	 ************************************************************************/
    virtual ~UDPServer();


    /************************************************************************
	 * This function does the socket Binding                                *
	 ************************************************************************/
    void bindUDP(unsigned short int server_port);

};

#endif