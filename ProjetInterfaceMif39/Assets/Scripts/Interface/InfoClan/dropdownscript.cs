using UnityEngine;
using System.Collections;
using UnityEngine.UI;
using System.Collections.Generic;

public class dropdownscript : MonoBehaviour {

	public RectTransform container;
	public bool IsOpen;
	ArrayList ClanList = new ArrayList(); //niveau 1
    Dictionary<GameObject, ArrayList> dico = new Dictionary<GameObject, ArrayList>();
    Dictionary<GameObject, ArrayList> DicoClanMembre = new Dictionary<GameObject, ArrayList>();

	// Use this for initialization
	void Start () {
		Button myButton = GetComponent<Button>();
		myButton.onClick.AddListener(inverseOpen);
		container = transform.FindChild("container").GetComponent<RectTransform>();
		IsOpen = false;
    
    	for (int i = 0; i <= 4; i++){ // creation des dropdown clans
            GameObject clan = Instantiate(Resources.Load("elementN1D")) as GameObject;
            clan.transform.SetParent(container);
            clan.transform.name = "Clan test "+i;
            clan.GetComponentInChildren<Text>().text = "Clan test "+i;
            clan.GetComponent<Image>().color = Color.blue;
            ClanList.Add(clan);
        }

        for (int i = 0; i < ClanList.Count; i++){ //creation des dropdown Membres et Comportement
        	GameObject clan = ClanList[i] as GameObject;
        	RectTransform container2 = clan.transform.FindChild("container").GetComponent<RectTransform>();




            GameObject Membre = Instantiate(Resources.Load("elementN1D")) as GameObject;
            Membre.transform.SetParent(container2);
            Membre.transform.name = "Membres";
            Membre.GetComponentInChildren<Text>().text = "Membres";
            Membre.GetComponent<Image>().color = Color.red;                	

            GameObject Comportement = Instantiate(Resources.Load("elementN1D")) as GameObject;
            Comportement.transform.SetParent(container2);
            Comportement.transform.name = "Comportements";
            Comportement.GetComponentInChildren<Text>().text = "Comportements";
            Comportement.GetComponent<Image>().color = Color.green;     

            ArrayList MembreEtComportement = new ArrayList();
            MembreEtComportement.Add(Membre);      
            MembreEtComportement.Add(Comportement); 

			//decalage des dropdown
			container2.offsetMin = new Vector2 (175,-1);//left-bottom
			container2.offsetMax = new Vector2 (200,25);//right-top


            dico.Add(clan, MembreEtComportement);

        }

        for (int i = 0; i < ClanList.Count; i++){ //creation des personnages dans membres
            GameObject clan = ClanList[i] as GameObject;

        	GameObject Membre = dico[clan][0] as GameObject;//MembreAndComportement[i*2] as GameObject; // chaque clan a deux sous dropdown
        	RectTransform container2 = Membre.transform.FindChild("container").GetComponent<RectTransform>();

            ArrayList temp = new ArrayList();
        	for(int j=0;j<2;j++){
        		GameObject membre = Instantiate(Resources.Load("elementN1D")) as GameObject;
            	membre.transform.SetParent(container2);
            	membre.transform.name = "Membre "+j+" (clan "+i+")";
	            membre.GetComponentInChildren<Text>().text = "Membre "+j+" (clan "+i+")";
	            membre.GetComponent<Image>().color = Color.yellow;
                temp.Add(membre);
				//decalage des dropdown
				container2.offsetMin = new Vector2 (200,-1);//left-bottom
				container2.offsetMax = new Vector2 (200,25);//right-top
        	}
            DicoClanMembre.Add(clan, temp);
                            	    
        }

        GameObject clant = ClanList[2] as GameObject;


	}


	
	// Update is called once per frame
	void Update () {

		Vector3 scale = container.localScale;
		scale.y = Mathf.Lerp(scale.y, IsOpen ? 1 :0, Time.deltaTime * 12);
		container.localScale = scale;  

	}

	void inverseOpen(){
		if(IsOpen){
			IsOpen = false;
		}else{
			IsOpen =true;
		}

	/*	for (int i = 0; i < ClanList.Count; i++){
			GameObject clan = ClanList[i] as GameObject;
			clan.GetComponent("dropdownsimple").IsOpen = false;
            }
		}*/


	}
}
