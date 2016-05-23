using UnityEngine;
using System.Collections;
using UnityEngine.EventSystems;
using System.Collections.Generic;

public class deplacementDeRectangle : MonoBehaviour {

    private int id;
    private bool keyUp;

    // Use this for initialization
    void Start () {

        keyUp = true;
        id = 0;
    }

    // Update is called once per frame
    void Update () {

        
        if (Input.GetButton("Fire1"))
        {

            PointerEventData cursor = new PointerEventData(EventSystem.current);
            cursor.position = Input.mousePosition;
            List<RaycastResult> objectsHit = new List<RaycastResult>();
            EventSystem.current.RaycastAll(cursor, objectsHit);
            int count = objectsHit.Count;

            for (int i = 0; i < count; i++)
            {

                //Debug.Log("MACHIN x:" + objectsHit[i].gameObject.tag);
                //                Debug.Log("MACHIN y:" + objectsHit[i].gameObject.transform.position.y);
                //              Debug.Log("MACHIN z:" + objectsHit[i].gameObject.transform.position.z);

                if (objectsHit[i].gameObject.tag == "UnRectangle")
                {
                    if(id == 0)
                    {
                        id = objectsHit[i].gameObject.GetInstanceID();
                    }
                                        
                    if(id == objectsHit[i].gameObject.GetInstanceID())
                    {
                        objectsHit[i].gameObject.transform.position = Input.mousePosition;



                    }
                }



            }


            /*if (keyUp == true )
            {
                keyUp = false;
               
                Debug.Log("Je rentre bien dans la boucle");



                if (Input.GetButtonUp("Fire1"))
                {
                    keyUp = true;
                    id = -666;
                }
            }
*/






        }
        if (Input.GetButtonUp("Fire1"))
        {
            id = 0;
            Debug.Log("Je passe dedans !!");
        }

    }
}
