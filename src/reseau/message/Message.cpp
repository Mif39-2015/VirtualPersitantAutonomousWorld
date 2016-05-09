/**
 * \file Message.cpp
 * \brief Implementation for Message.hpp
 */
#include "reseau/message/Message.hpp"
	
	
Message::Message(Client * c, std::string m): client(c), message(m) {}


Client * Message::getClient()
{
	return client;
}

std::string Message::getMessage()
{
	return message;
}
			
