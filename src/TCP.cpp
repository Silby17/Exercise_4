#include "TCP.h"

/************************************************************************
 * This is the TCP Class constructor		        					*
************************************************************************/
TCP::TCP() { }


/************************************************************************
	 * This is the TCP destructor      		        					*
************************************************************************/
TCP::~TCP() { }



void TCP::sendTCP(char *data, unsigned int data_len) {
    int sent_bytes = send(sock, data, data_len, 0);

    if(sent_bytes < 0){
        perror("Sent bytes < 0\n");
    }

}

string TCP::receiveTCP() {
    char buffer[BUFFER_SIZE];
    int expected_data_len = sizeof(buffer);
    //Puts received bytes into buffer and returns size of received data
    int read_bytes = recv(sock, buffer, expected_data_len, 0);

    //if no bytes connection closed
    if (read_bytes == 0) {
        cout << "connection is closed\n";
    }
    //error bytes < 0
    else if (read_bytes < 0) {
        cout << "error. not enough bytes read";
    }
        //prints recieved buffer
    else {
        cout << "Received data : " << buffer << endl;
        string str(buffer);
        return str;
    }
}