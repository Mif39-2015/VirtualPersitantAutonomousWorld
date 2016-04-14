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
#include <arpa/inet.h> //inet_addr
#include <unistd.h>    //write
#include <pthread.h> //for threading , link with lpthread
#include <fstream>
#include <string>
#include "message/Message.hpp"
#include "message/WorldChangeMessage.hpp"
#include "../server/WorldSimulator.hpp"
#include "../logging/Logger.hpp"
#include "AuthenticationModule.hpp"

typedef struct arg{
    const char * nom;
    int val;
} infos;

class WorldSimulator;

using namespace std;

/**
 * \class NetworkAdapter
 * \brief Link with the network block
 */
class NetworkAdapter {
private:
    AuthenticationModule auth;
    WorldSimulator* simulator;
    Logger* networkLogger;
    int socket_desc , client_sock , c , *new_sock;
    struct sockaddr_in server , client;
    infos *info;


public:
    NetworkAdapter(WorldSimulator* _simulator);
    NetworkAdapter(WorldSimulator* _simulator, bool logNetwork);
    void Init();
    void Run();
    void broadcastWorldChangesToclients();
};

#endif
