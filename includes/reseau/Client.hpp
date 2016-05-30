/**
 * \file Client.hpp
 * \brief Client class definition
 */
#ifndef _CLIENT_
#define _CLIENT_

#include <iostream>
#include <vector>
#include <thread>

#include "reseau/AuthenticationModule.hpp"
#include "reseau/MessageSender.hpp"
#include "reseau/message/Message.hpp"
#include "NetworkAdapter.hpp"
#include "NetworkManager.hpp"

class NetworkAdapter;
class NetworkManager;

using namespace std;

/**
 * \class Client
 * \brief Holds client information
 */
class Client {
public:
    Client(NetworkAdapter* _netAdapter, NetworkManager* _netManager, int _socket, AuthenticationModule* auth, MessageSender* sender);
		
    void setId(int _id);

    int getId();
    int getSocket();	
    void handleRequests(std::string message); // Run method
		
private:
    NetworkAdapter* netAdapter; // used to send and receive data
    NetworkManager* netManager; // used to access handle_user_command
    AuthenticationModule* authModule;    
		MessageSender* messSender;
    
    int id; // database ID
    int socket; // Socket fd
};

#endif
