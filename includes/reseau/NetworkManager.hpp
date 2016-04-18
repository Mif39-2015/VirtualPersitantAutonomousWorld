/**
 * \file NetworkManager.hpp
 * \brief NetworkManager class definition
 */
#ifndef _NETWORKMANAGER_
#define _NETWORKMANAGER_

#include "reseau/Client.hpp"


class Client;

/**
 * \class NetworkManager
 * \brief Link with the network block
 */
class NetworkManager {
	private:
		
		vector<Client*> clients;

	public:
		void addClient(Client* _newClient);
		void deleteClient(int _clientId);
		Client* getClientById(int _clientId);
};

#endif
