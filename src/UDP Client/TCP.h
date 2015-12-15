
#ifndef EXERCISE_4_TCP_H
#define EXERCISE_4_TCP_H
#include "udpTcpParent.h"

class TCP: public udpTcpParent{

public:

    /************************************************************************
	 * This is the TCP Class constructor		        					*
	 ************************************************************************/
    TCP();


    /************************************************************************
	 * This is the TCP destructor       		        					*
	 ************************************************************************/
    virtual ~TCP();


    /************************************************************************
	 * This function will send to the TCP Server                            *
	 ************************************************************************/
    void sendTCP(char* data, unsigned int data_len);


    /************************************************************************
	 * This will receive the info from the TCP Server                       *
	 ************************************************************************/
    void reveiveTCP();

};


#endif //EXERCISE_4_TCP_H