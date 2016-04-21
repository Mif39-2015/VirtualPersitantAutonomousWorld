/**
 * \file Client.cpp
 * \brief Implementation of Client.hpp
 */
#include "reseau/Client.hpp"


Client::Client(NetworkAdapter* _netAdapter, int _socket):
netAdapter(_netAdapter), id(-1), socket(_socket)
{
    this->requestHandler = new thread(&Client::handleRequests, this);
}

void Client::setId(int _id){
    this->id = _id;
}

int Client::getId(){
    return this->id;
}

int Client::getSocket(){
    return this->socket;
}

thread* Client::getThread(){
    return this->requestHandler;
}

void Client::handleRequests(){
    while(true){
        // listen for user messages
    }
}

void Client::sendMessage(string _message){
	this->netAdapter->sendMessageToClient(this->socket, _message);
}
