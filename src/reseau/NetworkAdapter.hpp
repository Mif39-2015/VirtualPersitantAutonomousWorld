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
#include "WorldChangesListener.hpp"
#include "AuthenticationModule.hpp"

typedef struct arg{
    const char * nom;
    int val;
} infos;

class WorldChangesListener;

using namespace std;

/**
 * \class NetworkAdapter
 * \brief Link with the network block
 */
class NetworkAdapter {
private:
    AuthenticationModule auth;
    WorldChangesListener* worldChangesListener;
    int socket_desc , client_sock , c , *new_sock;
    struct sockaddr_in server , client;
    infos *info;


public:
    NetworkAdapter(WorldChangesListener* _worldChangesListener);
    void Init();
    void Run();

};

#endif
