/****************************************
 * Yossi Silberhaft & Nava Shemoul		*
 * Exercise 4							*
 * File: udpTcpParent.h 				*
 ****************************************/
#ifndef EXERCISE_4_UDP_TCP_PARENT_H
#define EXERCISE_4_UDP_TCP_PARENT_H

#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include <unistd.h>
#include <iostream>
#define BUFFER_SIZE 4096
using namespace std;

class udpTcpParent{

protected:
    int sock;

public:
    /************************************************************************
	 * This is the udpTcpParent Class constructor							*
	 ************************************************************************/
    udpTcpParent();


    /************************************************************************
	 * This is the udpTcpParent Class destructor                            *
	 ************************************************************************/
    virtual ~udpTcpParent();

    /************************************************************************
	 * This function will create a new Socket   							*
	 ************************************************************************/
    void newSocket(int sock_type);


    /************************************************************************
	 * This is function will close the connection                           *
	 ************************************************************************/
    void closeConnection();

};


#endif
