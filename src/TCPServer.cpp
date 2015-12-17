/****************************************
* Yossi Silberhaft & Nava Shemoul		*
* Exercise 4							*
* File: TCPServer.cpp					*
****************************************/
#include "TCPServer.h"


/************************************************************************
 * This is the TCPServer Class constructor		        				*
 ************************************************************************/
TCPServer::TCPServer(){ }


/************************************************************************
 * This is the TCPServer Class destructor                               *
 ************************************************************************/
TCPServer::~TCPServer(){ }


/************************************************************************
 * This function will bind to all the IP Address of the host            *
 ************************************************************************/
void TCPServer::bindTCP(unsigned int server_port){
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    //binds to all ip address of the host
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(server_port);

    //binds a socket to a port number
    if (bind(this->sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        cout << "TCP Server error binding\n";
    }
}


/************************************************************************
 * This function will wait for incoming transmissions                   *
 ************************************************************************/
void TCPServer::listenTCP(int back_log){
    //The Host waits for incoming transmission
    if (listen(this->sock, back_log) < 0) {
        cout << "TCP Error Listening\n";
    }
}


/************************************************************************
 * This function returns a dedicated socket descriptor to               *
 * communicate with the client                                          *
 ************************************************************************/
void TCPServer::acceptTCP(){
    //will contain client ip address and port number
    struct sockaddr_in client_sin;
    unsigned int addr_len = sizeof(client_sin);

    //returns a dedicated socket descriptor to communicate with the client
    t_client_sock = accept(this->sock, (struct sockaddr *) &client_sin, &addr_len);

    if (t_client_sock < 0) {
        cout << "Error Accepting Client Socket < 0\n";
    }

    this->sock = t_client_sock;
}