/**
 * \file MessageSender.hpp
 * \brief Message sender class definition
 */
#ifndef _MESSAGE_SENDER_
#define _MESSAGE_SENDER_

#include <iostream>
#include <queue>
#include <thread>

#include "NetworkAdapter.hpp"
#include "NetworkManager.hpp"
#include "message/Message.hpp"

class NetworkAdapter;
class NetworkManager;
class Message;

using namespace std;

/**
 * \class Client
 * \brief Holds client information
 */
class MessageSender {
public:
    MessageSender(NetworkAdapter* _netAdapter, NetworkManager* _netManager);
	
	void addMessage(Message m);
	
    thread* getThread();
		
    void sendMessage(); // Run method
		
private:
    NetworkAdapter* netAdapter; // used to send and receive data
    NetworkManager* netManager; // used to access handle_user_command
    queue<Message> listMessage;
    
    thread* requestHandler; // Message sender thread
};

#endif

