using UnityEngine;
using System.Collections;

public class TestLanceur : MonoBehaviour {

	// Use this for initialization
	void Start () {
		 GameObject TextBoxManager = GameObject.Find("TextBoxManager");
		 TextBoxScript tbs = TextBoxManager.GetComponent<TextBoxScript>();
		 tbs.textecourant.text = "Test de niveau superieur ";
		 tbs.delay = 8;
	}
	
	// Update is called once per frame
	void Update () {
	
	}
}
