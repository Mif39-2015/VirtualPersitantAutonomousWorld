using UnityEngine;
using System.Collections;
using UnityEngine.UI;
using System.Collections.Generic;
using System.Linq;


public class testpie : MonoBehaviour {

    int nbwedge;
    Wedge firstwedge;
    float amount;
    List<Wedge> listWedge;
    List<int> valuePop;
    bool changed;
    float posX, posY,posZ;

	// Use this for initialization
	void Start () {
        changed = true;

        firstwedge = GetComponentInChildren<Wedge>();
        posX = firstwedge.transform.position.x; 
        posY = firstwedge.transform.position.y; 
        posZ = firstwedge.transform.position.z;
        Debug.Log(posX);
        Debug.Log(posY);
        Debug.Log(posZ);
	}
	
	// Update is called once per frame
	void Update () {

        if(changed)
        {
            valuePop = new List<int> { 25, 85, 95, 87, 25, 87, 96, 25, 45 };
            valuePop.Sort();
            listWedge = ConvertFromInts(valuePop);

            firstwedge = GetComponentInChildren<Wedge>();

             var children = new List<GameObject>();


             foreach (Transform child in transform) children.Add(child.gameObject);
                 children.ForEach(child => Destroy(child));

            



            listWedge.Sort();
            foreach (Wedge wed in listWedge)
            {
                Image test = wed.GetComponent<Image>();

                test.fillAmount = wed.fill;
                test.color = new Color(Random.value, Random.value, Random.value);
                wed.transform.SetParent(gameObject.transform);
                wed.transform.position = new Vector3(posX, posY, posZ);
            }
            changed = false;
        }
        
        else
        {
            
       /* var children = new List<GameObject>();


        foreach (Transform child in transform) children.Add(child.gameObject);
            {children.ForEach(child => Destroy(child));}*/

        }

        

	}

    List<Wedge> ConvertFromInts(List<int> powers)
    {
        float tempamount = 0;
        List<Wedge> wedges = new List<Wedge>();
        int total = powers.Sum(pkg => pkg);
        foreach(int value in powers)
        {
            Wedge tempwedge = Instantiate<Wedge>(firstwedge);
             amount =((float)value / total);
           
            
            tempamount += amount;

            tempwedge.fill = tempamount;
            wedges.Add(tempwedge);
        }

            return wedges;
    }
}
