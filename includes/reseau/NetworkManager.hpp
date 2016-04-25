/**
 * \file NetworkManager.hpp
 * \brief NetworkManager class definition
 */
#ifndef _NETWORKMANAGER_
#define _NETWORKMANAGER_

#include "reseau/Client.hpp"
#include "reseau/NetworkAdapter.hpp"
#include "logging/Logger.hpp"
// #include "reseau/AuthenticationModule.hpp"
#include "server/WorldSimulator.hpp"

#include <thread>

class WorldSimulator;
class NetworkAdapter;
class Client;

/**
 * \class NetworkManager
 * \brief Link with the network block
 */
class NetworkManager {
	private:
		WorldSimulator* simulator;
		NetworkAdapter* netAdapter;
		// AuthenticationModule* authModule;
		vector<Client*> clients;
		thread networkAdapterThread;

	public:
		NetworkManager(WorldSimulator* _simulator);
		// void addClient(Client* _newClient);
		void addClient(int socket);
		void deleteClient(int _clientId);
		Client* getClientById(int _clientId);
		void handleUserCommand(Client* c, string message);

		void broadcastMessage(string message);
};

#endif
