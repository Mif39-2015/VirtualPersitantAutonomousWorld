using UnityEngine;
using System.Collections;
using System.Collections.Generic;
using System.Text;
using System;
using System.IO;
using System.Text.RegularExpressions;

public class socketScript : MonoBehaviour {

	//variables
	private TCPConnection myTCP;
	private string serverMsg;
	public string msgToServer;
	public string nomFichier;	
	public string derniermessagelu = "";
    void Awake(){	
		//add a copy of TCPConnection to this game object  
		myTCP = gameObject.AddComponent<TCPConnection>();	
	}

	void Start(){
        if (myTCP.socketReady == false)
        {
                //try to connect	
                Debug.Log("Attempting to connect..");
                myTCP.setupSocket();
        }
        SendToServer(@"ceci est un texste");
    }
	
	void Update () {
		//keep checking the server for messages, if a message is received from server, it gets logged in the Debug console (see function below)
		string reponse = SocketResponse();
        int compteur = 0;

        if (reponse != "") {
            derniermessagelu = reponse;
            compteur++;
        }
        //Debug.Log("response = " + reponse);
        Debug.Log("le dernier message lu est = " + derniermessagelu);
    }

    //socket reading script
    string SocketResponse() {
		string serverSays = myTCP.readSocket();

		if (serverSays != "") {	
			Debug.Log("[SERVER]" + serverSays);
		}
        return serverSays;
	}

	//send message to the server
	public void SendToServer(string str) {
		myTCP.writeSocket(str);
		Debug.Log ("[CLIENT] -> " + str);	
	}	
}

