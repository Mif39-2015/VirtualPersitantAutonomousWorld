using UnityEngine;
using System.Collections;

public class AffichePanel : MonoBehaviour {

    public GameObject canvas;
    public TestElementActif tea;
	// Use this for initialization
	void Start () {
	
	}
	
	// Update is called once per frame
	void Update () {
	
	}

    public void Affiche()
    {
        if (canvas.tag == "CanvasEditor")
        {

            tea.canvasEditor = true;

        }
        canvas.SetActive(true);
    }
}
