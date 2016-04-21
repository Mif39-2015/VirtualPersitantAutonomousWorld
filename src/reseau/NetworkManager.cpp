/**
 * \file NetworkAdapter.cpp
 * \brief Implementation of NetworkManager.hpp
 */
#include "reseau/NetworkManager.hpp"

NetworkManager::NetworkManager(WorldSimulator* _simulator):
simulator(_simulator), netAdapter(new NetworkAdapter(this, true)), authModule(new AuthenticationModule())
{

}

// void NetworkManager::addClient(Client* _newClient){
// 	this->clients.push_back(_newClient);
// }

void NetworkManager::addClient(int socket){
	this->clients.push_back(new Client(this->netAdapter, socket));
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



