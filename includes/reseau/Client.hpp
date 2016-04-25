/**
 * \file Client.hpp
 * \brief Client class definition
 */
#ifndef _CLIENT_
#define _CLIENT_

#include <iostream>
#include <vector>
#include <thread>

#include "NetworkAdapter.hpp"

class NetworkAdapter;

using namespace std;

/**
 * \class Client
 * \brief Holds client information
 */
class Client {
public:
    Client(NetworkAdapter* _netAdapter, int _socket);
		
    void setId(int _id);

    int getId();
    int getSocket();
    thread* getThread();
		
    void handleRequests(); // Run method
    void sendMessage(string _message);
		
private:
    NetworkAdapter* netAdapter; // used to access database
    int id; // database ID
    int socket; // Socket fd
    thread* requestHandler; // Client thread
};

#endif
