using UnityEngine;
using System.Collections;

public class CatchObject : MonoBehaviour {

    public LayerMask rayMask;
    public GameObject lvlArt;
    // Use this for initialization
    void Start () {
	
	}
	
	// Update is called once per frame
	void Update () {
       /* if (Input.GetMouseButtonDown(0))
        {
            Ray ray = Camera.main.ScreenPointToRay(Input.mousePosition);
            RaycastHit hit;
            if (Physics.Raycast(ray, out hit, float.MaxValue, rayMask))
            {
                GameObject tile = hit.collider.gameObject.GetComponent<TileController>();
                if (tile != null)
                {
                    //dire au pingouin d'aller jusqu'a la tuile
                    GameObject penguinObject = GameObject.FindGameObjectWithTag("Player");
                    PenguinController pc = penguinObject.GetComponent<PenguinController>();
                    pc.WalkTo(tile);
                    positionActuelle.juice = positionActuelle.GetComponent<MeshRenderer>().material.GetColor("_Color");
                    positionActuelle.juice.r += 0.25f;
                    positionActuelle.juice.g += 0.25f;
                    positionActuelle.juice.b += 0.25f;
                    positionActuelle = tile;

                }
            }
        } */
    }
}

