using UnityEngine;
using System.Collections;
using UnityEngine.UI;

public class UnRectangle : MonoBehaviour {

    //public GameObject nouveauRectangle;

    // Use this for initialization
    void Start () {
	
	}
	
	// Update is called once per frame
	void Update () {
	
	}

    public void creerBouton()
    {

        Dropdown dropDownObject = GameObject.FindWithTag("DropdownComportement").GetComponent<Dropdown>();



        GameObject buttonSpawn = GameObject.FindWithTag("bouttonSpawn");
        //GameObject nouveauRectangle = GameObject.FindWithTag("UnRectangle");
        GameObject transformObject = Instantiate(gameObject, buttonSpawn.transform.position, buttonSpawn.transform.rotation) as GameObject;

        //dropDownObject.RefreshShownValue();
        //transformObject.GetComponent<Button>().GetComponentInChildren<Text>().text = "" + dropDownObject.GetComponentInChildren<Text>().text;
        transformObject.GetComponentInChildren<Text>().text = "" + dropDownObject.GetComponentInChildren<Text>().text;
        Debug.Log("value:" + dropDownObject.value);
        Debug.Log("itemText:" + dropDownObject.itemText);
        Debug.Log("options:" + dropDownObject.options);
        Debug.Log("captionText:" + dropDownObject.captionText);
        //Debug.Log(".GetComponentInChildren<Text>().text:" + dropDownObject.GetComponentInChildren<Text>().text);
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
