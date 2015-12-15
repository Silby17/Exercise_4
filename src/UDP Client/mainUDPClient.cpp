#include <string>
#include <iostream>
#include "UDPClient.h"

using namespace std;
#define IP_ADDRESS "127.0.0.1"
#define SERVER_PORT 5678

int main() {
    string out;
    bool run = true;
    // the string being sent
    //string data = "1 xyz Inception 148 2010 8.8 This is the description";
    //the size of string
    //int data_len = sizeof(data);
    UDPClient* client = new UDPClient;
    client->newSocket(SOCK_DGRAM);
    client->connectUDP(SERVER_PORT, IP_ADDRESS);

    while(run){
        cout << "Enter Input to send to server" << endl;
        char data[BUFFER_SIZE];
        cin.getline(data, BUFFER_SIZE);
        int data_len = sizeof(data);
        client->sendTo(IP_ADDRESS, SERVER_PORT, data);

    }

    client->closeConnection();
}
