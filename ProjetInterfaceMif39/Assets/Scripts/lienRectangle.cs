using UnityEngine;
using UnityEngine.UI;
using System.Collections;

public class lienRectangle : MonoBehaviour {

    // Use this for initialization

    public GameObject objectA;
    public GameObject objectB;
    public float grasseur;
    private Vector3 differenceVector;
    private float angle;
    private Image img;
    private Transform pointA;
    private Transform pointB;

    
    public void setObjectA(GameObject o)
    {
        this.objectA = o;
    
        Debug.Log("JE set Object A" + objectA.GetInstanceID());
    }

    public void setObjectB(GameObject o)
    {
        this.objectB = o;
        Debug.Log("JE set Object B" + this.objectB.GetInstanceID());
    }

    void Start () {
        /*if (objectB != null && objectA != null)
        {

            objectB = objectA = null;
        }
        */
    }
	
	// Update is called once per frame
	void Update () {
        //if (objectB != null && objectA != null)
        //{




        if (pointA == null && pointB == null)
            {
                pointA = objectA.GetComponent<Transform>();
                pointB = objectB.GetComponent<Transform>();
                img = gameObject.AddComponent<Image>();
                img.color = Color.red;
            }          
            
            differenceVector = new Vector3(pointB.position.x, pointB.position.y, pointB.position.z) - new Vector3(pointA.position.x, pointA.position.y, pointA.position.z);
            img.rectTransform.sizeDelta = new Vector2(differenceVector.magnitude, grasseur);
            img.rectTransform.pivot = new Vector2(0, 0.5f);
            img.rectTransform.position = pointA.position;
            angle = Mathf.Atan2(differenceVector.y, differenceVector.x) * Mathf.Rad2Deg;
            img.rectTransform.rotation = Quaternion.Euler(0, 0, angle);
        }


        
    //}
}
