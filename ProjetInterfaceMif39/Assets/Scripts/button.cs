using UnityEngine;
using System.Collections;

public class button : MonoBehaviour {

    Vector3 mousePosition, targetPosition;
    private Transform targetObject;
    private GameObject Comportement;
    private deplacementPanel DeplacementPanel;
    public GameObject LeButton;

    void Start () {

    }

    void Update()
    {
        targetObject = GetComponent<Transform>();
        Comportement = GameObject.FindWithTag("GameController");
        mousePosition = Input.mousePosition;
        DeplacementPanel = Comportement.GetComponent<deplacementPanel>();
        
        if (Input.GetButtonDown("Fire1"))
        {
            if (DeplacementPanel.selectione == true && DeplacementPanel.buttonn == LeButton)
            {
                DeplacementPanel.selectione = false;
                targetObject.position = mousePosition;
                
            }
        }
    }

    public void jenesaispascommentlappeler()
    {
        targetObject = GetComponent<Transform>();
        Comportement = GameObject.FindWithTag("GameController");
        mousePosition = Input.mousePosition;
        DeplacementPanel = Comportement.GetComponent<deplacementPanel>();
        
        if (DeplacementPanel.selectione == false)
            {
                DeplacementPanel.selectione = true;
                DeplacementPanel.buttonn = LeButton;
        }      
    }

    public void getId()
    {
        Debug.Log("L'id du button : " + GetInstanceID());
    }
}
