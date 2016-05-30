/**
 * \file NetworkManager.hpp
 * \brief NetworkManager class definition
 */
#ifndef _NETWORKMANAGER_
#define _NETWORKMANAGER_

#include "reseau/Client.hpp"
#include "reseau/NetworkAdapter.hpp"
#include "reseau/MessageSender.hpp"
#include "reseau/AuthenticationModule.hpp"
#include "logging/Logger.hpp"
#include "server/WorldSimulator.hpp"
#include "tool/cJSON.hpp"

#include <thread>

class WorldSimulator;
class NetworkAdapter;
class MessageSender;
class Client;

/**
 * \class NetworkManager
 * \brief Link with the network block
 */
class NetworkManager {
	private:
		WorldSimulator* simulator;
		NetworkAdapter* netAdapter;
		AuthenticationModule* authModule;
    MessageSender* messSender;
		vector<Client*> clients;
		thread networkAdapterThread;

	public:
		NetworkManager(WorldSimulator* _simulator);
		// void addClient(Client* _newClient);
		void addClient(int socket);
		void deleteClient(int _clientId);
		Client* getClientById(int _clientId);
    Client* getClientBySocket(int _clientSocket);
		void handleUserCommand(int socket_message, string message);

		void broadcastMessage(string message);
};

#endif
