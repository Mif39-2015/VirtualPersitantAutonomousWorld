using UnityEngine;
using System.Collections;

public class minimap : MonoBehaviour {

	// Use this for initialization
	void Start () {
	
	}
	
	// Update is called once per frame
	void Update () {
	
	}

    void OnGUI()
    {
        GUI.skin.button.onHover.textColor = Color.cyan;
        Debug.Log(GUI.skin.button.hover.textColor);
    }
}
