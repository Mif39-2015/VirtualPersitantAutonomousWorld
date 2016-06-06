using UnityEngine;
using System.Collections;
using UnityEngine.EventSystems;
using System.Collections.Generic;

public class deplacementDeRectangle : MonoBehaviour {

    private int id;
    private bool keyUp;
    private Animation annie;
    private RaycastResult rcr;

    void Start () {

        keyUp = true;
        id = 0;
    }

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

                if (objectsHit[i].gameObject.tag == "UnRectangle")
                {
                    if(id == 0)
                    {
                        id = objectsHit[i].gameObject.GetInstanceID();
                    }
                                        
                    if(id == objectsHit[i].gameObject.GetInstanceID())
                    {
                        keyUp = false;
                        rcr = objectsHit[i];

                    }
                }

            }

            if (keyUp == false)
            {
                rcr.gameObject.transform.position = Input.mousePosition;
                annie = rcr.gameObject.GetComponent<Animation>();
                annie.Play();
            }
        }

        if (Input.GetButtonUp("Fire1"))
        {
            annie.Stop();
            id = 0;
            keyUp = true;
        }

    }
}
