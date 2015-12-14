#include "UDPClient.h"

#define IP_ADDRESS "127.0.0.1"
#define SERVER_PORT 3000

int main() {
    // the string being sent
    char data[] = "Do you want to build a snowman?";
    //the size of string
    int data_len = sizeof(data);

    UDPClient* client = new UDPClient;

    client->newSocket(SOCK_STREAM);
    client->connectUDP(SERVER_PORT, IP_ADDRESS);

    client->sendTo(data, data_len);

    client->receiveFrom();

    client->closeConnection();
}