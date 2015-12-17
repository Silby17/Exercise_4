/****************************************
 * Yossi Silberhaft & Nava Shemoul						*
 * Exercise 4							*
 * File: UDPClient.cpp     				*
 ****************************************/
#include "UDPClient.h"

/************************************************************************
 * This is the UDPClient Constructor                                    *
 ************************************************************************/
UDPClient::UDPClient(){ }


/************************************************************************
 * This is the UDPClient destructor                                     *
 ************************************************************************/
UDPClient::~UDPClient(){    }


/************************************************************************
 * This function will connect the UDP clients to its port               *
 ************************************************************************/
void UDPClient::connectUDP(unsigned int server_port, char* ip_address){
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));

    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr(ip_address);
    sin.sin_port = htons(server_port);

}