using UnityEngine;
using System.Collections;



public class affichageBouton : MonoBehaviour {

    public GameObject canvas;
    public float rate = 0.2f;
    private float next;
    public string truc;
 

    void Start () {
   
    }
	
	
	void Update () {
        if (Input.GetButton(truc) && Time.time > next)
        {
            next = Time.time + rate;

            Debug.Log("Coucou ! Je suis un pinguin asthmatique", canvas);
            if (canvas.activeSelf.Equals(false))
            {
                canvas.SetActive(true);
                Debug.Log("canvas desactivé");
            }
            else
            {
                canvas.SetActive(false);
                Debug.Log("canvas desactivé");
            }
        }
    }
}

