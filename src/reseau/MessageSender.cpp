/**
 * \file Client.cpp
 * \brief Implementation of Client.hpp
 */
#include <string>
 
#include "reseau/MessageSender.hpp"


MessageSender::MessageSender(NetworkAdapter* _netAdapter, NetworkManager* _netManager):
netAdapter(_netAdapter), netManager(_netManager)
{
    this->requestHandler = new thread(&MessageSender::sendMessage, this); //P-e this à rajouter
}

void MessageSender::sendMessage()
{
	while(1)
	{
		if(!listMessage.empty())
		{
			Message m = listMessage.front();
			listMessage.pop();
			this->netAdapter->sendMessageToClient(m.getClient()->getSocket(), m.getMessage());
		}
	}
}

void MessageSender::addMessage(Message m)
{
	this->listMessage.push(m);
}

thread* MessageSender::getThread()
{
	 return this->requestHandler;
}
		

