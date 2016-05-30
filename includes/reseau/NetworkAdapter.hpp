/**
 * \file NetworkAdapter.hpp
 * \brief NetworkAdapter class definition
 */
#ifndef _NETWORKADAPTER_
#define _NETWORKADAPTER_

#include <iostream>
#include <vector>
#include <cstdio>
#include <string.h>    //strlen
#include <cstdlib>    //strlen
#include <sys/socket.h>
#include <poll.h>
#include <arpa/inet.h> //inet_addr
#include <unistd.h>    //write
#include <pthread.h> //for threading , link with lpthread
#include <fstream>
#include <string>
#include "message/Message.hpp"
#include "server/WorldSimulator.hpp"
#include "logging/Logger.hpp"
#include "AuthenticationModule.hpp"
#include "reseau/NetworkManager.hpp"

class NetworkManager;
using namespace std;

/**
 * \class NetworkAdapter
 * \brief Link with the network block
 */
class NetworkAdapter {
private:
    NetworkManager* netManager;
    Logger* networkLogger;
    int listenSocket;
    // int client_sock, c , *new_sock;
    // infos *info;
    int socket_desc, clientSock;
    struct sockaddr_in server , client;
	

public:
    NetworkAdapter(NetworkManager* _netManager);
    NetworkAdapter(NetworkManager* _netManager, bool logNetwork);
    int Init(int maxPendingConnections);
    void Run();

    void sendMessageToClient(int socket, string message);
    int receiveMessage(int socket, string &message);
    void retablirBuffer(string &message);

    void pollSockets();

};

#endif
