using UnityEngine;
using System.Collections;

public class LoginScreen : MonoBehaviour {

	private string u = "username";
	private string p = "password";

	private string usernameString = string.Empty;
	private string passwordString = string.Empty;

	private Rect windowRect = new Rect(0,0,Screen.width, Screen.height);

	// Use this for initialization
	void Start () {
	}
	
	// Update is called once per frame
	void Update () {
	
	}

	void OnGUI()
	{
		GUI.Window(0,windowRect, WindowFunction, "Connexion");
	}

	void WindowFunction (int windowID) {
		usernameString = GUI.TextField (new Rect (Screen.width / 3, 2 * Screen.height / 5, Screen.width / 3, Screen.height / 10), usernameString, 10);
		passwordString = GUI.PasswordField (new Rect (Screen.width / 3, 2 * Screen.height / 3, Screen.width / 3, Screen.height / 10), passwordString, "*"[0],10);
		
		
		if(GUI.Button(new Rect(Screen.width/2, 4* Screen.height/5, Screen.width/8, Screen.height/8), "Connexion"))
		{
			if(usernameString == u && passwordString == p)
			{
				Debug.Log("Bienvenue John !");
			}
			else{Debug.Log("Mauvais pseudonyme ou mot de passe");}
		}
		GUI.Label(new Rect(Screen.width/3, 35 * Screen.height/100, Screen.width/5, Screen.height/8), "Pseudonyme");
		GUI.Label(new Rect(Screen.width/3, 62 * Screen.height/100, Screen.width/8, Screen.height/8), "Mot de passe");				
	}
}
