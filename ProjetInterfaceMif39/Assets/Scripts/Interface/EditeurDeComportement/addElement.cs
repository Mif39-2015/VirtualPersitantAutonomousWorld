using UnityEngine;
using System.Collections;
using UnityEngine.UI;

public class AddElement : MonoBehaviour
{

    public void creerBouton()
    {

        Dropdown dropDownObject = GameObject.FindWithTag("DropdownComportement").GetComponent<Dropdown>();
        GameObject buttonSpawn = GameObject.FindWithTag("bouttonSpawn");
        GameObject nouveauBouton = GameObject.FindWithTag("UnRectangle");
        GameObject transformObject = Instantiate(nouveauBouton, buttonSpawn.transform.position, buttonSpawn.transform.rotation) as GameObject;
        transformObject.GetComponent<Button>().GetComponentInChildren<Text>().text = "" + dropDownObject.GetComponentInChildren<Text>().text;
        Debug.Log("value:" + dropDownObject.value);
        Debug.Log("itemText:" + dropDownObject.itemText);
        Debug.Log("options:" + dropDownObject.options);
        Debug.Log("captionText:" + dropDownObject.captionText);
        Debug.Log(".GetComponentInChildren<Text>().text:" + dropDownObject.GetComponentInChildren<Text>().text);
        transformObject.transform.parent = GameObject.FindWithTag("panelPrincipal").transform;

    }
}
