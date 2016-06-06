using UnityEngine;
using System.Collections;
using UnityEngine.UI;

public class button : MonoBehaviour {

    Vector3 mousePosition, targetPosition;
    private Transform targetObject;
    private GameObject Comportement;
    private deplacementPanel DeplacementPanel;
    public GameObject LeButton;
    //public string[] listOptionDropDown;


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


    public void creerBouton()
    {
        
        Dropdown dropDownObject = GameObject.FindWithTag("DropdownComportement").GetComponent<Dropdown>();

        

        GameObject buttonSpawn = GameObject.FindWithTag("bouttonSpawn");
        GameObject nouveauBouton = GameObject.FindWithTag("buttonComportement");
        GameObject transformObject = Instantiate(nouveauBouton, buttonSpawn.transform.position, buttonSpawn.transform.rotation) as GameObject;

        //dropDownObject.RefreshShownValue();
        transformObject.GetComponent<Button>().GetComponentInChildren<Text>().text = "" + dropDownObject.GetComponentInChildren<Text>().text;

        Debug.Log("value:"+ dropDownObject.value);
        Debug.Log("itemText:" + dropDownObject.itemText);
        Debug.Log("options:" + dropDownObject.options);
        Debug.Log("captionText:" + dropDownObject.captionText);
        Debug.Log(".GetComponentInChildren<Text>().text:" + dropDownObject.GetComponentInChildren<Text>().text);
        /*Debug.Log("" + dropDownObject.);
        Debug.Log("" + dropDownObject.);
        Debug.Log("" + dropDownObject.);
        Debug.Log("" + dropDownObject.);
        Debug.Log("" + dropDownObject.);
        Debug.Log("" + dropDownObject.);
        Debug.Log("" + dropDownObject.);
        Debug.Log("" + dropDownObject.);*/


        transformObject.transform.parent = GameObject.FindWithTag("panelPrincipal").transform;

    }
}
// button1.GetComponentInChildren<Text>().text = "la di da";

/*
 using UnityEngine;
 using UnityEngine.UI;
 
 public Dropdown myDropdown;
 
 void Start() {
     myDropdown.onValueChanged.AddListener(delegate {
         myDropdownValueChangedHandler(myDropdown);
     });
 }
 void Destroy() {
     myDropdown.onValueChanged.RemoveAllListeners();
 }
 
 private void myDropdownValueChangedHandler(Dropdown target) {
     Debug.Log("selected: "+target.value);
 }
 
 public void SetDropdownIndex(int index) {
     myDropdown.value = index;
 }

*/
