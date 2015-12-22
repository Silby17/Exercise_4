/****************************************
 * Yossi Silberhaft & Nava Shemoul		*
 * Exercise 4							*
 * File: main.cpp						*
 ****************************************/
#include <string>
#include <iostream>
#include <cstring>
#include "udpTcpParent.h"
#include "UDP.h"
#include "TCP.h"
#include "TCPClient.h"
#include "UDPClient.h"

using namespace std;

int main(int argc, char **argv) {
    //Gets the type from the passed arguments
    int type = atoi(argv[1]);
    //Gets the IP from passed arguments
    string ip = argv[2];
    //Gets the post number from passed arguments
    int port = atoi(argv[3]);
    //Sets a boolean for running
    bool run = true;
    string output;
    string received;
    //Converts the IP to a char* for passing to function
    char *cstr = new char[ip.length() + 1];
    strcpy(cstr, ip.c_str());

    //Checks if the type is UDP or TCP
    if(type == 0){
        //If UDP then create the Connection
        UDPClient* udpClient = new UDPClient;
        udpClient->newSocket(SOCK_DGRAM);
        udpClient->connectUDP(port, cstr);
        //Start the running of sending and receiving to the Server
        while(run){
            char data[BUFFER_SIZE];
            //Get input from the user
            cin.getline(data, BUFFER_SIZE);
            int data_len = sizeof(data);

            //If the Client entered -1 to end the program
            if(data[0] == '-' && data[1] == '1'){
                run = false;
                //Send the -1 to the server to end
                udpClient->sendTo(cstr, port, data);

                //CLose connection of the Client
                udpClient->closeConnection();
                break;
            }
            //Send into the the server
            udpClient->sendTo(cstr, port, data);
            //Receive message from the server
            output = udpClient->receiveFrom();
            //If the message received is greater than 0 then print output
            if(output.size() > 0){
                cout << output << endl;
            }
        }
        //Close connection
        udpClient->closeConnection();
    }
        //Else if the type is a TCP Connection
    else if(type == 1){
        TCPClient* tcpClient = new TCPClient;
        tcpClient->newSocket(SOCK_STREAM);
        tcpClient->connectTCP(port, cstr);
        //Starts the running of the exchange of data
        while(run){
            char data[BUFFER_SIZE];
            //Gets input to send to server
            cin.getline(data, BUFFER_SIZE);
            int data_len = sizeof(data);

            //Checks if the user entered in -1 to end the program
            if(data[0] == '-' && data[1] == '1'){
                run = false;
                tcpClient->sendTCP(data, data_len);
                tcpClient->closeConnection();
                break;
            }
            //Sends info to the server
            tcpClient->sendTCP(data, data_len);
            //Receives info from the server
            received = tcpClient->receiveTCP();
            //Prints out received info from the server
            cout << received << endl;
        }
        //Close connection
        tcpClient->closeConnection();
    }

    return 0;
}