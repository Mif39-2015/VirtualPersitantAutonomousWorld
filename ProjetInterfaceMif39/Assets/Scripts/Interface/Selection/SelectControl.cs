using UnityEngine;
using System.Collections;
using System.Collections.Generic;
using UnityEngine.EventSystems;

public class SelectControl : MonoBehaviour
{

    private List<ListMaterial> saveMesh;
    private string hitemp;
    private GameObject redo;
    public AfficheInfoSurvol aff;
    public GameObject canvasInfoClan;
    public GameObject canvasFenetreInfo;
    public GameObject canvasEditor;
    public TestElementActif tea;
    
    // Use this for initialization
    void Start()
    {
        //aff = AfficheInfoSurvol();
        //aff = GameObject.FindGameObjectWithTag("InfoPanel").GetComponent<AfficheInfoSurvol>();
        aff.click = false;
        aff.popup = false;
        tea.canvasInfoPanel = false;
        saveMesh = new List<ListMaterial>();
        hitemp = "";
        redo = new GameObject();
        canvasInfoClan.SetActive(false);
        canvasEditor.SetActive(false);
        canvasFenetreInfo.SetActive(false);
    }

    // Update is called once per frame
    void Update()
    {
        RaycastHit hit;

        Ray ray = Camera.main.ScreenPointToRay(Input.mousePosition);

        aff.infoCanvas.transform.localPosition = Vector3.zero;
        aff.infoCanvas.transform.rotation = Camera.main.gameObject.transform.localRotation;

        if (Physics.Raycast(ray, out hit))
        {
            Selectable Hit = hit.collider.gameObject.GetComponent<Selectable>();
            GameObject gm = hit.collider.gameObject;

            if (Hit == null)
            {              
                if (gm != null)
                {
                    if (gm.tag.Equals("Ressources") || gm.tag.Equals("Batiments"))
                    {
                        aff.popup = true;
                        aff.infoCanvas.transform.SetParent(Hit.transform);
                    }
                }

                if (saveMesh.Count != 0)
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
                    aff.popup = false;
                }
               
            }
            else
            {
                Debug.Log("Cible touchée : " + Hit.name);
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

                if (Input.GetMouseButtonDown(0))
                {
                    aff.popup = false;
                    if(Hit.name == "Tank") // à renommer Agent quand on mergera avec affichage
                    {
                        tea.canvasInfoPanel = true;
                        canvasInfoClan.SetActive(true);
                    }
                    if(Hit.name == "Refinery")
                    {
                        tea.canvasFenetre = true;
                        canvasFenetreInfo.SetActive(true);
                    }

                    

                }
                else
                {
                    if (canvasInfoClan.activeSelf.Equals(false))
                    {
                        aff.popup = true;
                        aff.infoCanvas.transform.SetParent(Hit.transform);

                        if (Input.GetMouseButtonDown(1))
                        {
                            // afficher la fenetre d'info de l'objet selectable au clic de la souris
                            if (aff.click == true)
                            {
                                aff.click = false;
                            }
                            else
                            {
                                aff.click = true;
                            }

                        }
                    }

                   

                }


               

            }

            

        }
        else
        {
            //Debug.Log("Oui, c'est bien de l'air.");
        }

    }
}