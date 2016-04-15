/**
 * \file NetworkAdapter.cpp
 * \brief Implementation of NetworkAdapter.hpp
 */
#include "NetworkAdapter.hpp"


NetworkAdapter::NetworkAdapter(WorldSimulator* _simulator)
    : NetworkAdapter(_simulator, false)
{

}

NetworkAdapter::NetworkAdapter(WorldSimulator* _simulator, bool logNetwork)
    : auth(), simulator(_simulator)
{
    if(logNetwork){
        networkLogger = new Logger("network.log");
    } else {
        networkLogger = NULL;
    }
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
    server.sin_port = htons( 8887 );

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
    std::string ligne;
    if(file)
    {
        while(getline(file, ligne))
        {
            ligne+="\n";
            cout << ligne << endl;

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

int receptionFichier(string filename,int sock){
	int result =0;
	char client_message[2000];
	result = recv(sock , client_message , 2000 , 0);
        ofstream fichier(filename, ios::out | ios::app);
        fichier << client_message;
        cout << client_message;
        retablir_buffer(client_message);
        fichier.close();
	return result ;
	
} 

void envoiMessageFichierAvecFlag(string filename,int sock ,string flag ,string flagFin ){
	
	int taille = strlen(flag.c_str());
	int taillefin = strlen(flagFin.c_str());
	cout<<taille<<endl;
	write(sock , flag.c_str() ,taille);
	
	envoieMessageFichier((char*)filename.c_str(),sock);
	write(sock,flagFin.c_str(),taillefin);
	
}

void envoiMessageFichierUpdate(string filename , int sock){
	envoiMessageFichierAvecFlag(filename,sock,"UPDATE\n","FINUPDATE\n");
}

void envoiMessageChaine(string chaine, int sock){
	int taille = strlen(chaine.c_str());
	write(sock , (chaine.c_str()) , taille);
}
void envoiMessageChaineAvecFlag(string chaine,int sock,string flag,string flagFin){
	int taille = strlen(flag.c_str());
	int taillefin = strlen(flagFin.c_str());
	//cout<<taille<<endl;
	write(sock , flag.c_str() ,taille);
	
	envoiMessageChaine(chaine,sock);

	write(sock,flagFin.c_str(),taillefin);
}

void envoiMessageChaineUpdate(string chaine,int sock){
	envoiMessageChaineAvecFlag(chaine,sock,"UPDATE\n","\nFINUPDATE\n");
}

void* connection_handler(void *socket_desc)
{
    //Get the socket descriptor
    infos sock = *(infos*)socket_desc;
    int read_size;
    char *message , client_message[2000];
    read_size = 1;

    printf("le numero de la socket est : %d \n", sock.val);

    //Receive a message from client
    //cout << "[DEBUG]" << endl;
    envoiMessageFichierUpdate("testenvoi.txt", sock.val);
    envoiMessageChaineUpdate("Ceci est ma chaine", sock.val);
    cout << "envoie de fichier" << endl;

    while( read_size > 0 )
    {
	read_size=receptionFichier("testreception.txt",sock.val);

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




void NetworkAdapter::Run(){
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




