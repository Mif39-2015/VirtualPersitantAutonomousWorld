/**
 * \file NetworkAdapter.cpp
 * \brief Implementation of NetworkAdapter.hpp
 */
#include "NetworkAdapter.hpp"


NetworkAdapter::NetworkAdapter(WorldChangesListener* _worldChangesListener)
    : auth(), worldChangesListener(_worldChangesListener)
{
	
}

void NetworkAdapter::Init(){
    //Create socket
    socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    if (socket_desc == -1)
    {
        printf("Could not create socket");
    }
    puts("Socket created");

    //Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons( 8888 );

    //Bind
    if( bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0)
    {
        //print the error message
        perror("bind failed. Error");
        return;
    }
    puts("bind done");

    //Listen
    listen(socket_desc , 3);

    //Accept and incoming connection
    puts("Waiting for incoming connections...");
    c = sizeof(struct sockaddr_in);


    //Accept and incoming connection
    puts("Waiting for incoming connections...");
    c = sizeof(struct sockaddr_in);
}

void concat (char * mess1, char * mess2){
    strcat(mess1, mess2);
}

void retablir_buffer(char * message){
    memset(message, 0, strlen(message));
}

void envoieMessageFichier(const char * fichier, int socket){
    ifstream file(fichier, ios::in);
    char *message;
    cout << "je suis dans la fonction" << endl;
    std::string ligne;
    if(file)
    {
        while(getline(file, ligne))
        {
            cout << ligne << endl; // on l'affiche
            
            // concat((char *) ligne.c_str(), "\r\n");
            ligne += "\r\n";
            
            write(socket , (ligne.c_str()) , strlen(ligne.c_str()));
            retablir_buffer((char *) ligne.c_str());

        }
        file.close();  // on ferme le fichier
    }
    else
    {
        cerr << "Impossible d'ouvrir le fichier !" << endl;
    }
}

void* connection_handler(void *socket_desc)
{
    //Get the socket descriptor
    infos sock = *(infos*)socket_desc;
    int read_size;
    char *message , client_message[2000];

    printf("le numero de la socket est : %d \n", sock.val);

    //Receive a message from client
    while( (read_size = recv(sock.val , client_message , 2000 , 0)) > 0 )
    {
        //Send the message back to client
        envoieMessageFichier("test.txt", sock.val);
    }

    if(read_size == 0)
    {
        puts("Client disconnected");
        fflush(stdout);
    }
    else if(read_size == -1)
    {
        perror("recv failed");
    }

    //Free the socket pointer
    free(socket_desc);

    return 0;
}

void NetworkAdapter::Run() {
    while( (client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c)) )
    {
        puts("Connection accepted");
        pthread_t sniffer_thread;
        new_sock = (int*) malloc(sizeof(int));
        *new_sock = client_sock;
        info = (infos*) malloc(sizeof(infos));
        info->val = client_sock;
        info->nom = "buffer";

        if( pthread_create( &sniffer_thread , NULL ,  connection_handler , (void*) info) < 0)
        {
            perror("could not create thread");
            return;
        }

        //Now join the thread , so that we dont terminate before the thread
        //pthread_join( sniffer_thread , NULL);
        puts("Handler assigned");
    }

    if (client_sock < 0)
    {
        perror("accept failed");
        return;
    }
}

