/****************************************
 * Yossi Silberhaft						*
 * Exercise 4							*
 * File: udpTcpParent.cpp				*
 ****************************************/

#include "udpTcpParent.h"


/************************************************************************
 * This is the udpTcpParent constructor                                 *
************************************************************************/
udpTcpParent::udpTcpParent() { }


/************************************************************************
 * This is the udpTcpParent Destructor                            *
************************************************************************/
udpTcpParent::~udpTcpParent() { }


/************************************************************************
 * This function will receive a socket number and will create a new     *
 * socket with the number received                                      *
************************************************************************/
void udpTcpParent::newSocket(int sock_type) {

}

/************************************************************************
 * This function will close down the connection that was made           *
************************************************************************/
void udpTcpParent::closeConnection() {
    close(sock);
}