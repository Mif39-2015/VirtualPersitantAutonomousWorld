/**
 * \file NetworkAdapter.cpp
 * \brief Implementation of NetworkManager.hpp
 */
#include "reseau/NetworkManager.hpp"

NetworkManager::NetworkManager(WorldSimulator* _simulator):
simulator(_simulator),
netAdapter(new NetworkAdapter(this, true)),
authModule(new AuthenticationModule())
{
	netAdapter->Init(10);
	networkAdapterThread = thread(&NetworkAdapter::Run, netAdapter);
	thread(&NetworkAdapter::pollSockets, netAdapter);
  messSender = new MessageSender(netAdapter, this);
}


void NetworkManager::addClient(int socket){
	this->clients.push_back(new Client(this->netAdapter, this, socket, authModule, messSender));
}

void NetworkManager::deleteClient(int _clientId){
	unsigned int i = 0;
	for(Client* cl : this->clients){
		if(cl->getId() == _clientId){
			this->clients.erase(this->clients.begin()+i);
			delete cl;
		}
		i++;
	}
}

Client* NetworkManager::getClientById(int _clientId){
	for(Client* cl : this->clients){
		if(cl->getId() == _clientId){
			return cl;
		}
	}
	return NULL;
}
vector<Client*> NetworkManager::getClients(){
	return this->clients;
}

Client* NetworkManager::getClientBySocket(int _clientSocket){
	for(Client* cl : this->clients){
		if(cl->getSocket() == _clientSocket){
			return cl;
		}
	}
	return NULL;
}

void NetworkManager::handleUserCommand(int socket_message, string message)
{
  Client* c = getClientBySocket(socket_message);
  if(c != NULL)
  {
    c->handleRequests(message);
  }
  else 
  {
    c = new Client(this->netAdapter, this, socket_message, authModule, messSender);
    messSender->addMessage(Message(c, "{\"messageType\":\"error\",\"errorMessage\":\"Unknow client\",\"code\": \"1004\"\"status\":\"fail\"}"));
  }
	
}


