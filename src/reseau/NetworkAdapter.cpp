/**
 * \file NetworkAdapter.cpp
 * \brief Implementation of NetworkAdapter.hpp
 */
#include "reseau/NetworkAdapter.hpp"


NetworkAdapter::NetworkAdapter(NetworkManager* _netManager)
    : NetworkAdapter(_netManager, false)
{

}

NetworkAdapter::NetworkAdapter(NetworkManager* _netManager, bool logNetwork)
    :netManager(_netManager)
{
    if(logNetwork){
        networkLogger = new Logger("network.log");
    } else {
        networkLogger = NULL;
    }
}


int NetworkAdapter::Init(int maxPendingConnections){
    //Create socket
    listenSocket = socket(AF_INET , SOCK_STREAM , 0);
    if (listenSocket == -1)
    {
        printf("Could not create socket\n");
        return -1;
    }
    puts("Socket created");

    //Prepare the sockaddr_in structure
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons( 8887 );

    //Bind
    if( bind(listenSocket,(struct sockaddr *)&server , sizeof(server)) < 0)
    {
        //print the error message
        perror("bind failed. Error");
        return -2;
    }
    puts("bind done");

    //Listen
    listen(listenSocket , maxPendingConnections);

    return 0;

    //Accept and incoming connection
    // puts("Waiting for incoming connections...");
    // c = sizeof(struct sockaddr_in);


    // //Accept and incoming connection
    // puts("Waiting for incoming connections...");
    // c = sizeof(struct sockaddr_in);

	/*~~
    //Create socket
    listenSocket = socket(AF_INET , SOCK_STREAM , 0);
    if (listenSocket == -1)
    {
        return -1;
    }

    //Prepare the sockaddr_in structure
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons( 8887 );

    //Bind
    if( bind(listenSocket,(struct sockaddr *)&server , sizeof(server)) < 0)
    {
        return -2;
    }
    cout << "bound" << endl;

    // //Listen
    // listen(listenSocket , maxPendingConnections);

    // //Accept and incoming connection
    // puts("Waiting for incoming connections...");
    // c = sizeof(struct sockaddr_in);


    // //Accept and incoming connection
    // puts("Waiting for incoming connections...");
    // c = sizeof(struct sockaddr_in);

    ~~*/
}

// void concat (char * mess1, char * mess2){
//     strcat(mess1, mess2);
// }

void retablir_buffer(char * message){
     memset(message, 0, strlen(message));
}



// void envoieMessageFichier(const char * fichier, int socket){
//     ifstream file(fichier, ios::in);
//     char *message;
//     std::string ligne;
//     if(file)
//     {
//         while(getline(file, ligne))
//         {
//             ligne+="\n";
//             cout << ligne << endl;

//             write(socket , (ligne.c_str()) , strlen(ligne.c_str()));
//             retablir_buffer((char *) ligne.c_str());

//         }
//         file.close();  // on ferme le fichier
//     }
//     else
//     {
//         cerr << "Impossible d'ouvrir le fichier !" << endl;
//     }

// }

// int receptionFichier(string filename,int sock){
// 	int result =0;
// 	char client_message[2000];
// 	result = recv(sock , client_message , 2000 , 0);
//         ofstream fichier(filename, ios::out | ios::app);
//         fichier << client_message;
//         cout << client_message;
//         retablir_buffer(client_message);
//         fichier.close();
// 	return result ;
	
// } 

// void envoiMessageFichierAvecFlag(string filename,int sock ,string flag ,string flagFin ){
	
// 	int taille = strlen(flag.c_str());
// 	int taillefin = strlen(flagFin.c_str());
// 	cout<<taille<<endl;
// 	write(sock , flag.c_str() ,taille);
	
// 	envoieMessageFichier((char*)filename.c_str(),sock);
// 	write(sock,flagFin.c_str(),taillefin);
	
// }

// void envoiMessageFichierUpdate(string filename , int sock){
// 	envoiMessageFichierAvecFlag(filename,sock,"UPDATE\n","FINUPDATE\n");
// }

// void envoiMessageChaine(string chaine, int sock){
// 	int taille = strlen(chaine.c_str());
// 	write(sock , (chaine.c_str()) , taille);
// }
// void envoiMessageChaineAvecFlag(string chaine,int sock,string flag,string flagFin){
// 	int taille = strlen(flag.c_str());
// 	int taillefin = strlen(flagFin.c_str());
// 	//cout<<taille<<endl;
// 	write(sock , flag.c_str() ,taille);
	
// 	envoiMessageChaine(chaine,sock);

// 	write(sock,flagFin.c_str(),taillefin);
// }

// void envoiMessageChaineUpdate(string chaine,int sock){
// 	envoiMessageChaineAvecFlag(chaine,sock,"UPDATE\n","\nFINUPDATE\n");
// }

// void* connection_handler(void *listenSocket)
// {
//     //Get the socket descriptor
//     infos sock = *(infos*)listenSocket;
//     int read_size;
//     char *message , client_message[2000];
//     read_size = 1;

//     printf("le numero de la socket est : %d \n", sock.val);

//     //Receive a message from client
//     //cout << "[DEBUG]" << endl;
//     envoiMessageFichierUpdate("testenvoi.txt", sock.val);
//     envoiMessageChaineUpdate("Ceci est ma chaine", sock.val);
//     cout << "envoie de fichier" << endl;

//     while( read_size > 0 )
//     {
// 	read_size=receptionFichier("testreception.txt",sock.val);

//     }



//     if(read_size == 0)
//     {
//         puts("Client disconnected");
//         fflush(stdout);
//     }
//     else if(read_size == -1)
//     {
//         perror("recv failed");
//     }

//     //Free the socket pointer
//     free(listenSocket);

//     return 0;
// }




void NetworkAdapter::Run(){
    socklen_t addrlen = sizeof(struct sockaddr_in);
    while( (clientSock = accept(listenSocket, (struct sockaddr *)&client, &addrlen)) )
    {
        if (clientSock > 0){
            puts("Connection accepted");
            netManager->addClient(clientSock);
        }
        string message = "ceci est un test\n";
        string message2 = "Ceci est un autre test\n";
        string message3;
        sendMessageToClient(clientSock, message);
        sendMessageToClient(clientSock, message2);
        
        receiveMessage(clientSock, message3);
        
    }
    if (clientSock < 0)
    {
        perror("Accept failed");
        return;
    }
}

void NetworkAdapter::sendMessageToClient(int socket, string message){
    write(socket , (message.c_str()) , strlen(message.c_str()));
}

void NetworkAdapter::retablirBuffer(string &message){
	message.clear();
	memset((char *) message.c_str(), 0, strlen(message.c_str()));
}

int NetworkAdapter::receiveMessage(int socket, string &message){
	int result =0;
	retablirBuffer(message);
 	result = recv(socket , (char *) message.c_str() , 2000 , 0);
 	if(result > 0){
		string test = message.c_str();
		message = test;
	}		
 	return result ;
} 
