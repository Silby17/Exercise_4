#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include "TCP.h"
using namespace std;

class TCPCLient: public TCP{


    /************************************************************************
	 * This is the TCPClient Constructor                                    *
	 ************************************************************************/
    TCPCLient();


    /************************************************************************
	 * This is the TCPClient destructor                                     *
	 ************************************************************************/
    virtual ~TCPCLient();


    /************************************************************************
	 * This function connects the TCP client to its Port                    *
	 ************************************************************************/
    void connectTCP(unsigned int server_port, char* ip_address);

};


#endif
