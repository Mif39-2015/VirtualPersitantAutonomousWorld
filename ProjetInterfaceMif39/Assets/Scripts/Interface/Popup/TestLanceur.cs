using UnityEngine;
using System.Collections;

public class TestLanceur : MonoBehaviour {

    public TextBoxScript tbs;

	// Use this for initialization
	void Start () {
		 GameObject TextBoxManager = GameObject.Find("TextBoxManager");
		 tbs.textecourant.text = "Test de niveau superieur ";
		 tbs.delay = 8;
	}
	
	// Update is called once per frame
	void Update () {
	
	}
}
