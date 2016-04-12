using UnityEngine;
using System.Collections;
using UnityEngine.UI;

public class TextBoxScript : MonoBehaviour {

	public GameObject textBox;
	public Text textecourant;
	public float delay = 5; // delai du popup par defaut

	// Use this for initialization
	void Start (){

		//textecourant.text = "Test de string super cool";
		textBox.SetActive(true);
		StartCoroutine (Degrade());

	}
	
	// Update is called once per frame
	void Update () {
		//double alpha =  GetComponent<Renderer>().material.color.a;
		//alpha = alpha  * 0.5;
		// tentaive de transparence
		
	}

	IEnumerator Degrade(){
       yield return new WaitForSeconds(delay);  
		textBox.SetActive(false);
    }


	

}
