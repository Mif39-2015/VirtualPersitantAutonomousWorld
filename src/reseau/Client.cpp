/**
 * \file Client.cpp
 * \brief Implementation of Client.hpp
 */
#include <string>
 
#include "reseau/Client.hpp"


Client::Client(NetworkAdapter* _netAdapter, NetworkManager* _netManager, int _socket, AuthenticationModule* auth, MessageSender* sender):
netAdapter(_netAdapter), netManager(_netManager), authModule(auth), messSender(sender), id(-1), socket(_socket)
{
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


void Client::handleRequests(std::string message){
  
    //TODO: Gestion de la requêtes et envoi de la réponse à MessageSender
    
    
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
        setId(id);		
        messSender->addMessage(Message(this, "{\"messageType\":\"loginResult\",\"status\":\"success\"}"));		
      }
      else
      {
        //Message d'erreur auth fail        
        messSender->addMessage(Message(this, "{\"messageType\":\"error\",\"errorMessage\":\"Auth fail\",\"code\": \"1001\"\"status\":\"fail\"}"));		
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
        setId(id);
        
        messSender->addMessage(Message(this, "{\"messageType\":\"registerResult\",\"status\":\"success\"}"));
      }
      else
      {
        //Message d'erreur register fail       
        messSender->addMessage(Message(this, "{\"messageType\":\"error\",\"errorMessage\":\"Register fail\",\"code\":\"1002\"\"status\":\"fail\"}"));
      }	
    }
    else
    {
      messSender->addMessage(Message(this, "{\"messageType\":\"error\",\"errorMessage\":\"Unknown command\",\"code\":\"1003\"\"status\":\"fail\"}"));
    }
}
