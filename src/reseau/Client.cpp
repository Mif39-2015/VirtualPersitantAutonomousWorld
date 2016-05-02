/**
 * \file Client.cpp
 * \brief Implementation of Client.hpp
 */
#include <string>
 
#include "reseau/Client.hpp"


Client::Client(NetworkAdapter* _netAdapter, NetworkManager* _netManager, int _socket):
netAdapter(_netAdapter), netManager(_netManager), id(-1), socket(_socket)
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
        std::string message = netAdapter->receiveMessage(socket);
        netManager->handleUserCommand(this, message);
    }
}

void Client::sendMessage(string _message){
	this->netAdapter->sendMessageToClient(this->socket, _message);
}
