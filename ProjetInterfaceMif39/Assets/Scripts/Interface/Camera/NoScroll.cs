using UnityEngine;
using System.Collections;

public class NoScroll : MonoBehaviour {
    /* 
    Script qui gère les zones de non-scrolling sur les cotés: minimap (si active) - chat - popup (si active) - panel echap - panel info 
        pour un rajout de "redzone": 
        1) tagger le canvas en question
        2) rajouter un booleen dans le script TestElementActif correspondant a l'activité ou non de l'element (canvas).
        3) selon les SetActive: 
            - si c'est par un bouton pour l'activation/désactivation: il faut rajouter une condition dans le script d'afficheBouton (dans les switch en trouvant le tag)
            - si c'est par une fermeture par la petite Croix: il faut repasser le booleen en question a "false" dans le script Croix (et pour le true, c'est mettre le booleen a true a l'endroit ou on fait le setActive(true);
            - si c'est comme la fenetre de popup .... ???
        */

    public bool isOnRedZone;
    private GameObject mmap;
    private GameObject popup;
    private GameObject chatbox;
    public TestElementActif tea;
	// Use this for initialization
	void Start () {
        isOnRedZone = true;
       
       

        

    }
	
	// Update is called once per frame
	void Update () {
        Vector2 mousePos;
        mousePos = Input.mousePosition;
        float minimapWidth = 0.0f;
        float minimapHeight = 0.0f;
        float popupWidth = 0.0f;
        float popupHeight = 0.0f;
        float screenx = Screen.width;
        float screeny = Screen.height;

        // le chat est toujours actif, on recup donc ses valeurs
        GameObject chatbox = GameObject.FindWithTag("ChatBox");
        float chatWidth = chatbox.GetComponent<RectTransform>().rect.width;
        float chatHeight = chatbox.GetComponent<RectTransform>().rect.height;
        float chatPosx = chatbox.GetComponent<RectTransform>().position.x;
        float chatPosy = chatbox.GetComponent<RectTransform>().position.y;
        Debug.Log(chatPosx + " " + chatPosy);

        // cas du popup
        if (tea.canvasPopup)
        {
            GameObject popup = GameObject.FindWithTag("PanelPopup");
            popupWidth = popup.GetComponent<RectTransform>().rect.width;
            popupHeight = popup.GetComponent<RectTransform>().rect.height;
        }


        // cas de la minimap (scrolling lorsqu'elle est inactive, sinon redzone !
        if (tea.canvasMinimap)
        {
            GameObject mmap = GameObject.FindWithTag("Minimap");
            minimapWidth = mmap.GetComponent<RectTransform>().rect.width;
            minimapHeight = mmap.GetComponent<RectTransform>().rect.height;
        }
        /* définition des "red zone" de non scrolling 8-D */
       if ( (tea.canvasInfoPanel.Equals(true)) || (tea.canvasFenetre.Equals(true)) ||
            (mousePos.x > (screenx - minimapWidth) && mousePos.y < minimapHeight) ||
           ( (mousePos.x < chatWidth+chatPosx && mousePos.y < chatHeight+chatPosy) && (mousePos.x > chatPosx && mousePos.y > chatPosy))||
            (mousePos.x > ((screenx/2)-(popupWidth/2)) && mousePos.x < ((screenx / 2) + (popupWidth / 2)) && mousePos.y > screeny - popupHeight)
          )
        {
            isOnRedZone = false;
        }
        else
        {
            isOnRedZone = true;
        }
      /* if (mousePos.x < chatWidth && mousePos.y < chatHeight)
        {
            isOnRedZone = false;
        }
        if (mousePos.x > (screenx - minimapWidth) && mousePos.y < minimapHeight)
        {
            isOnRedZone = false;
        }
        if (mousePos.x < () && mousePos.y > (screeny - mou)
        {
            isOnRedZone = false;
        } */

    }
}
