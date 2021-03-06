/****************************************
 * Yossi Silberhaft & Nava Shemoul						*
 * Exercise 4							*
 * File: UDP.h          				*
 ****************************************/
#ifndef UDP_H
#define UDP_H
#include "udpTcpParent.h"

class UDP: public udpTcpParent {

private:
    int port;

public:
    /************************************************************************
	 * This is the UDP Class constructor		        					*
	 ************************************************************************/
    UDP();


    /************************************************************************
	 * This is the UDP class destructor           							*
	 ************************************************************************/
    virtual ~UDP();


    /************************************************************************
	 * This function will send data to the designated port number           *
	 ************************************************************************/
    void sendTo(char* ip_address, int port_num, string data);


    /************************************************************************
	 * THis function will receive data from the port                        *
	 ************************************************************************/
    std::string receiveFrom();


    /************************************************************************
	 * This will return the port Number                                     *
	 ************************************************************************/
    int getPortNumber();

};

#endif