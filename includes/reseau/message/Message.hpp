/**
 * \file Message.hpp
 * \brief Message class definition. Also defines message IDs
 */
#ifndef _MESSAGE_
#define _MESSAGE_

// *** Message IDs definition
//  * Recieved from client (starts from 0)



#include <string>
#include <iostream>
#include "reseau/Client.hpp"

class Client;

/**
 * \class Message
 * \brief Abstract super-class for all messages sent and recieved over the network
 */
class Message {
	public:
		Message(Client* c, std::string m);
		Client* getClient();
		std::string getMessage();
			
	private:
		Client* client;
		std::string message;
};

#endif
