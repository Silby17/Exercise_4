/****************************************
 * Yossi Silberhaft						*
 * Exercise 4							*
 * File: UDP.p          				*
 ****************************************/
#include "UDP.h"

/************************************************************************
* This is the UDP Class constructor		        					    *
************************************************************************/
UDP::UDP() { }


/************************************************************************
* This is the UDP class destructor      						    	*
************************************************************************/
UDP::~UDP() { }

/************************************************************************
* This function will receive an IP Address and a port number            *
* and will send the info to the designated destination                  *
************************************************************************/
void UDP::sendTo(char *ip_address, int port_num, string data) {
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));

    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr(ip_address);
    sin.sin_port = htons(port_num);

    int data_len = data.size();

    //send a packet of data to an ip address and port
    int sent_bytes = sendto(sock, data.c_str(), data_len, 0, (struct sockaddr *) &sin, sizeof(sin));
    if (sent_bytes < 0) {
        perror("error writing to socket\n");
    }
}


/************************************************************************
* This function receives data from the UDP Server                       *
************************************************************************/
string UDP::receiveFrom() {
    struct sockaddr_in from;
    unsigned int from_len = sizeof(struct sockaddr_in);;
    char buffer[BUFFER_SIZE];
    int bytes = recvfrom(sock, buffer, sizeof(buffer), 0, (struct sockaddr *) &from, &from_len);
    if (bytes < 0) {
        cout << "bytes < 0";
    }
    else{
        string str(buffer);
        return str;
        port = ntohs(from.sin_port);
    }
}


int UDP::getPortNumber() {
    return this->port;
}