using UnityEngine;
using UnityEngine.UI;
using System.Collections;

public class AfficheInfoSurvol : MonoBehaviour {

    public GameObject infoCanvas;
    public bool click;
    public bool popup;

	// Use this for initialization
	void Start () {
        infoCanvas.SetActive(false);
        click = false;
        popup = false;

    }
	
	// Update is called once per frame
	void Update () {
       
        if (click)
        {
            infoCanvas.SetActive(true);
        }
        else
        {
            infoCanvas.SetActive(false);
            if (popup)
            {
                infoCanvas.SetActive(true);
            }
            else
            {
                infoCanvas.SetActive(false);
            }
            
        }

	}
}
