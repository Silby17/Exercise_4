#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include "TCP.h"
using namespace std;

class TCPClient: public TCP {

public:
    /************************************************************************
	 * This is the TCPClient Constructor                                    *
	 ************************************************************************/
    TCPClient();


    /************************************************************************
	 * This is the TCPClient destructor                                     *
	 ************************************************************************/
    virtual ~TCPClient();


    /************************************************************************
	 * This function connects the TCP client to its Port                    *
	 ************************************************************************/
    void connectTCP(unsigned int server_port, char* ip_address);

};


#endif
