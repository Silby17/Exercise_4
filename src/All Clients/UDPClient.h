/****************************************
 * Yossi Silberhaft & Nava Shemoul		*
 * Exercise 4							*
 * File: UDPClient.h     				*
 ****************************************/
#ifndef UDPCLIENT_H
#define UDPCLIENT_H
#include "UDP.h"
using namespace std;

class UDPClient: public UDP{

public:
    /************************************************************************
	 * This is the UDPClient Constructor                                    *
	 ************************************************************************/
    UDPClient();


    /************************************************************************
	 * This is the UDPClient destructor                                     *
	 ************************************************************************/
    virtual ~UDPClient();


    /************************************************************************
	 * This function will connect the UDP clients to its port               *
	 ************************************************************************/
    void connectUDP(unsigned int server_port, char* ip_address);

};
#endif
