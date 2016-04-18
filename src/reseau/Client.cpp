/**
 * \file Client.cpp
 * \brief Implementation of Client.hpp
 */
#include "reseau/Client.hpp"


Client::Client(int _socket)
    : id(-1), socket(_socket)
{
    this->requestHandler = new thread(&Client::listenForRequests, this);
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

void Client::listenForRequests(){
    while(true){
        // listen for user messages
    }
}

void sendMessageToClient(string _message){
	
}
