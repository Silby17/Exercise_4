#include <string>
#include <iostream>
#include <cstring>
#include "udpTcpParent.h"
#include "UDP.h"
#include "TCP.h"
#include "TCPClient.h"
#include "UDPClient.h"
#define BUFFER_SIZE 10000

using namespace std;

int main(int argc, char **argv) {
    string type = argv[1];
    string ip = argv[2];
    int port = atoi(argv[3]);
    bool run = true;
    string output;
    string str;
    char *cstr = new char[ip.length() + 1];
    strcpy(cstr, ip.c_str());

    if(type == "UDP"){
        UDPClient* udpClient = new UDPClient;
        udpClient->newSocket(SOCK_DGRAM);
        udpClient->connectUDP(port, cstr);
        while(run){
            char data[BUFFER_SIZE];
            cin.getline(data, BUFFER_SIZE);
            int data_len = sizeof(data);
            udpClient->sendTo(cstr, port, data);
            if(data[0] == '-' && data[1] == '1'){
                run = false;
                break;
            }
            output = udpClient->receiveFrom();
            if(output.size() > 0){
                cout << output << endl;
            }
        }
        udpClient->closeConnection();

    }
    else if(type == "TCP"){
        TCPClient* tcpClient = new TCPClient;
        tcpClient->newSocket(SOCK_STREAM);
        tcpClient->connectTCP(port, cstr);
        while(run){
            char data[BUFFER_SIZE];
            cin.getline(data, BUFFER_SIZE);
            int data_len = sizeof(data);

            tcpClient->sendTCP(data, data_len);
            if(data[0] == '-' && data[1] == '1'){
                run = false;
                break;
            }
        }
        tcpClient->closeConnection();
    }

    return 0;
}

