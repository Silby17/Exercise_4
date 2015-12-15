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
    //socket() will create a socket and return a descriptor
    int try_socket = socket(AF_INET, sock_type, 0);

    if(try_socket < 0){
        perror("Error creating Socket\n");
    }
    else {
        sock = try_socket;
    }

}

/************************************************************************
 * This function will close down the connection that was made           *
************************************************************************/
void udpTcpParent::closeConnection() {
    close(sock);
}