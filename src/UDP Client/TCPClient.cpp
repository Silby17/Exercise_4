#include "TCPClient.h"



/************************************************************************
* This is the TCPClient Constructor                                    *
************************************************************************/
TCPClient::TCPClient() { }

/************************************************************************
* This is the TCPClient Constructor                                    *
************************************************************************/
TCPClient::~TCPClient() { }


/************************************************************************
* This function will connect the TCP client to its server by using      *
 * the given Port and IP Address                                        *
************************************************************************/
void TCPClient::connectTCP(unsigned int server_port, char *ip_address) {
    struct sockaddr_in sin;

    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr(ip_address);
    sin.sin_port = htons(server_port);

    //makes the connection return error if connection not made
    if (connect(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        cout << "error. connecting Tcp client\n";
    }
}