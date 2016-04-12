using UnityEngine;
using System.Collections;
using System.Collections.Generic;

public class SelectControl : MonoBehaviour
{

    private List<ListMaterial> saveMesh;
    private string hitemp;
    private GameObject redo;
    // Use this for initialization
    void Start()
    {
        saveMesh = new List<ListMaterial>();
        hitemp = "";
        redo = new GameObject();
    }

    // Update is called once per frame
    void Update()
    {
        RaycastHit hit;

        Ray ray = Camera.main.ScreenPointToRay(Input.mousePosition);

        if (Physics.Raycast(ray, out hit))
        {
            // Debug.Log("HIT!");
            Selectable Hit = hit.collider.gameObject.GetComponent<Selectable>();

            if (Hit == null)
            {
                if(saveMesh.Count != 0)
                {
                    GameObject redo = GameObject.Find(hitemp);
                    MeshRenderer[] mr = redo.GetComponentsInChildren<MeshRenderer>();
                    foreach (MeshRenderer mesh in mr)
                    {
                        foreach (ListMaterial l in saveMesh)
                        {
                            if (mesh.name == l.idMeshString)
                            {
                                foreach(Material mat in mesh.materials)
                                {
                                    mat.shader = Shader.Find("Standard");
                                    // on remet le shader original mais pour le moment, c'est seulement sous le tag "Standard" ... or tout les objets sélectionnable ne seront pas forcement en Standard
                                }
                                
                            
                            }
                        }
                    }
                    saveMesh.Clear();
                }
               
                // Debug.LogError("rien à select"+Hit.gameObject.name);
            }
            else
            {
                Debug.Log("Cible touchée : " + Hit.id);
                hitemp = Hit.name;
                MeshRenderer[] mrs = Hit.GetComponentsInChildren<MeshRenderer>();
                foreach(MeshRenderer mesh in mrs)
                {
                    ListMaterial l = new ListMaterial();
                    l.idMeshString = mesh.name;
                    l.Matmesh = (Material[]) mesh.materials.Clone();
                    //l.Matmesh = mesh.materials;
                    if (saveMesh.Find(item => item.idMeshString==l.idMeshString) != null)
                    {
                       // Debug.Log("existe deja");
                    }
                    else
                    {
                        saveMesh.Add(l);
                    }
                           
                    
                    
                    //Debug.Log(saveMesh.Count);
                    for (int i=0; i<mesh.materials.Length; i++)
                    {
                        mesh.materials[i].shader = Shader.Find("Outlined/Diffuse");
        
                      //  Debug.Log(mesh.materials[i].name);
                    }
                }
                
            }

            if (Input.GetMouseButtonDown(0))
            {
            }

        }
        else
        {
            //Debug.Log("Oui, c'est bien de l'air.");
        }
    }
}