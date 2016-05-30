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
}

// void NetworkManager::addClient(Client* _newClient){
// 	this->clients.push_back(_newClient);
// }

void NetworkManager::addClient(int socket){
	this->clients.push_back(new Client(this->netAdapter, this, socket));
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

void NetworkManager::handleUserCommand(Client* c, string message)
{
	cout << "Received user command : " << endl;
	cout << message << endl;
	cJSON * messageJSON = cJSON_Parse(message.c_str());
	cJSON * messageTypeJSON = cJSON_GetObjectItem(messageJSON, "messageType");
	string messageType = cJSON_Print(messageTypeJSON);
	if(messageType == "login")
	{
		cJSON * usernameJSON = cJSON_GetObjectItem(messageJSON, "username");
		cJSON * passwordJSON = cJSON_GetObjectItem(messageJSON, "password");
		string username = cJSON_Print(usernameJSON);
		string password = cJSON_Print(passwordJSON);
		//Vérifier id mdp dans la bdd
		int id = authModule->authClient(username, password);
		if(id != -1)
		{
			//Récupérer l'id et le stocker dans la structure client 
			c->setId(id);				
			c->sendMessage("{\"messageType\":\"loginResult\",\"status\":\"success\"}");
		}
		else
		{
			//Message d'erreur auth fail
			c->sendMessage("{\"messageType\":\"error\",\"errorMessage\":\"Auth fail\",\"code\": \"1001\"\"status\":\"fail\"}");
		}	
	}
	else if(messageType == "register")
	{
		cJSON * usernameJSON = cJSON_GetObjectItem(messageJSON, "username");
		cJSON * passwordJSON = cJSON_GetObjectItem(messageJSON, "password");
		string username = cJSON_Print(usernameJSON);
		string password = cJSON_Print(passwordJSON);
		int id = authModule->registerClient(username, password, ""); // MAIL A SUPPRIMER
		if(id != -1)
		{
			//Récupérer l'id et le stocker dans la structure client 
			c->setId(id);
			c->sendMessage("{\"messageType\":\"registerResult\",\"status\":\"success\"}");
		}
		else
		{
			//Message d'erreur register fail
			c->sendMessage("{\"messageType\":\"error\",\"errorMessage\":\"Register fail\",\"code\":\"1002\"\"status\":\"fail\"}");
		}	
	}
	else
	{
		c->sendMessage("{\"messageType\":\"error\",\"errorMessage\":\"Unknown command\",\"code\":\"1003\"\"status\":\"fail\"}");
	}
}


