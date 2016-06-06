using UnityEngine;
using System.Collections;
using UnityEngine.UI;

public class UnRectangle : MonoBehaviour {

    public lienRectangle lienDebut;
    public lienRectangle lienFin;

    void Start () {

        if(gameObject.GetComponent<Animation>() != null)
        {
            gameObject.GetComponent<Animation>().Stop();
        }

  

            
	}

    public void setRectangleLienDebutA( GameObject g)
    {
        this.lienDebut.setObjectA(g);
    }

    public void setRectangleLienDebutB(GameObject g)
    {
        this.lienDebut.setObjectB(g);
    }

    public void creerBouton()
    {

        Dropdown dropDownObject = GameObject.FindWithTag("DropdownComportement").GetComponent<Dropdown>();
        GameObject buttonSpawn = GameObject.FindWithTag("bouttonSpawn");
        GameObject transformObject = Instantiate(gameObject, buttonSpawn.transform.position, buttonSpawn.transform.rotation) as GameObject;
        transformObject.GetComponentInChildren<Text>().text = "" + dropDownObject.GetComponentInChildren<Text>().text;
        Debug.Log("value:" + dropDownObject.value);
        Debug.Log("itemText:" + dropDownObject.itemText);
        Debug.Log("options:" + dropDownObject.options);
        Debug.Log("captionText:" + dropDownObject.captionText);
        transformObject.transform.parent = GameObject.FindWithTag("panelPrincipal").transform;

    }
}
