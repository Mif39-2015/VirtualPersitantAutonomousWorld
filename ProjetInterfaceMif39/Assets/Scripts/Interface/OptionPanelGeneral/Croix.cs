using UnityEngine;
using UnityEngine.UI;
using System.Collections;

public class Croix : MonoBehaviour {

    public GameObject canvas;
    public TestElementActif tea;
	// Use this for initialization
	void Start () {
	
	}
	
	// Update is called once per frame
	void Update () {
	
	}

    public void fermer()
    {
        
        if (canvas.tag == "CanvasFenetreInfo")
        {
            tea.canvasFenetre = false;
        }
        
        if (canvas.tag == "CanvasInfoClan")
        {
            
            tea.canvasInfoPanel = false;
            
        }
        if (canvas.tag == "CanvasEditor")
        {

            tea.canvasEditor = false;

        }
        canvas.SetActive(false);
    }


}
