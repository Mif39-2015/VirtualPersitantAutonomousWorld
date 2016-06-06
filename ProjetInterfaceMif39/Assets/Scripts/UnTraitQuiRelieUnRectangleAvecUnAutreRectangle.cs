using UnityEngine;
using UnityEngine.UI;
using System.Collections;
using UnityEngine.EventSystems;
using System.Collections.Generic;

public class UnTraitQuiRelieUnRectangleAvecUnAutreRectangle : MonoBehaviour {


    private int id, idRecTemp;
    private bool keyUp,rec1,rec2;
    private Animation annie;
    private RaycastResult rcr;
    public GameObject lienRectangle;
    private bool recDebut, recFin;
    private GameObject objectRecDebut, objectRecFin;
    private GameObject lienObjectTemp;


    void Start () {
        keyUp = true;
        rec1 = rec2 = recDebut = recFin = false;
        id = 0;

    }

    void Update()
    {

        if (Input.GetButtonDown("Fire2"))
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
                    if (id == 0)
                    {
                        id = objectsHit[i].gameObject.GetInstanceID();
                    }

                    if (id == objectsHit[i].gameObject.GetInstanceID())
                    {
                        keyUp = false;
                        rcr = objectsHit[i];
                    }
                }
            }

            if (keyUp == false)
            {
                
                annie = rcr.gameObject.GetComponent<Animation>();
                annie.Play();
                
                if(recDebut == false)
                {
                    objectRecDebut = rcr.gameObject;
                    rcr.gameObject.GetComponent<Image>().color = Color.red;
                    recDebut = true;
                    idRecTemp = id;
                    
                }
                else
                {
                    if (recFin == false && idRecTemp != id)
                    {
                        objectRecFin = rcr.gameObject;
                        rcr.gameObject.GetComponent<Image>().color = Color.red;
                        recFin = true;

                    }
                }
            }            
        }

        if (Input.GetButtonUp("Fire2"))
        {
            annie.Stop();
            id = 0;
            
            //Debug.Log("recDebut:" + recDebut);
            //Debug.Log("recFin:" + recFin);

            if (recFin == true && recDebut == true)
            {
                objectRecDebut.GetComponent<Image>().color = Color.white;
                objectRecFin.GetComponent<Image>().color = Color.white;

                lienObjectTemp = Instantiate(lienRectangle, new Vector3(0.0f, 0.0f, 0.0f), new Quaternion(0.0f, 0.0f, 0.0f, 0.0f)) as GameObject;
                lienObjectTemp.transform.SetParent(GameObject.FindWithTag("panelPrincipal").transform);
                lienObjectTemp.transform.SetAsFirstSibling();
                objectRecDebut.GetComponent<UnRectangle>().lienDebut = lienObjectTemp.GetComponent<lienRectangle>();
                objectRecDebut.GetComponent<UnRectangle>().setRectangleLienDebutA(objectRecDebut);
                objectRecDebut.GetComponent<UnRectangle>().setRectangleLienDebutB(objectRecFin);

                objectRecFin = null;
                objectRecDebut = null;
                recFin = false;
                recDebut = false;
                keyUp = true;

            }
            
        }

    }
}
