#ifndef EXERCISE_4_TCPSERVER_H
#define EXERCISE_4_TCPSERVER_H

#include "TCP.h"

using namespace std;

class TCPServer: public TCP {


public:

    /************************************************************************
	 * This is the TCPServer Class constructor		        				*
	 ************************************************************************/
    TCPServer();


    /************************************************************************
	 * This is the TCPServer Class destructor                               *
	 ************************************************************************/
    virtual ~TCPServer();


    /************************************************************************
	 * This function will bind to all the IP Address of the host            *
	 ************************************************************************/
    void bindTCP(unsigned int server_port);

    /************************************************************************
	 * This function will wait for incoming transmissions                   *
	 ************************************************************************/
    void listenTCP(int back_log);


    /************************************************************************
	 * This function returns a dedicated socket descriptor to               *
     * communicate with the client                                          *
	 ************************************************************************/
    void acceptTCP();



};
#endif
