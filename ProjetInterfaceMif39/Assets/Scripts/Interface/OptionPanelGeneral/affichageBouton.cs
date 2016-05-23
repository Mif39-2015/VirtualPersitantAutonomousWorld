using UnityEngine;
using System.Collections;
using UnityEngine.UI;



public class affichageBouton : MonoBehaviour {

    public GameObject canvas;
    public float rate = 0.2f;
    private float next;
    public string truc;
    public TestElementActif tea;
    private InputField focus;
 

    void Start () {
        tea.canvasPopup = true;
        tea.canvasMinimap = true;
    }
	
	
	void Update () {
        focus = GameObject.FindGameObjectWithTag("IFieldChat").GetComponent<InputField>();
        if(focus.isFocused!=true)
        {
            if (Input.GetButton(truc) && Time.time > next)
            {
                next = Time.time + rate;

                Debug.Log("Coucou ! Je suis un pinguin asthmatique", canvas);
                if (canvas.activeSelf.Equals(false))
                {
                    canvas.SetActive(true);
                    switch (canvas.tag)
                    {
                        case "CanvasMap":
                            tea.canvasMinimap = true;
                            break;
                        // rajouter un cas en fonction des panels affichés si affecté par NoScroll ...
                        default:
                            break;
                    }

                    Debug.Log("canvas desactivé");
                }
                else
                {
                    switch (canvas.tag)
                    {
                        case "CanvasMap":
                            tea.canvasMinimap = false;
                            break;
                        // rajouter un cas en fonction des panels affichés si affecté par NoScroll ...
                        default:
                            break;


                    }
                    canvas.SetActive(false);
                    Debug.Log("canvas desactivé");
                }
            }
        }

    }
}

