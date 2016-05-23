using UnityEngine;
using System.Collections;

public class MenuManager : MonoBehaviour {
	public enum MenuStates { Out, EscapeMenu, OptionsMenu };
    public MenuStates currentState;
    
	public Transform escapePanel;
	public Transform optionsPanel;
	
	// Use this for initialization
	void Start () {
		escapePanel.gameObject.SetActive(false);
        optionsPanel.gameObject.SetActive(false);
		currentState = MenuStates.Out;
	}
	
	// Update is called once per frame
	void Update () {
		if (Input.GetKeyDown(KeyCode.Escape))
		{
			escape();
		}
	}
	
	//Press escape key
	public void escape() 
	{
		if(currentState == MenuStates.EscapeMenu)
		{
			closeEscapePanel();
        }
        else {
            openEscapePanel();
        }
	}
	
	//Close the escape panel
	public void closeEscapePanel()
	{
		escapePanel.gameObject.SetActive(false);
        optionsPanel.gameObject.SetActive(false);
        currentState = MenuStates.Out;
        //Time.timeScale = 1;
	}
	
	//Open the escape panel
	public void openEscapePanel()
	{
		escapePanel.gameObject.SetActive(true);
        optionsPanel.gameObject.SetActive(false);
        currentState = MenuStates.EscapeMenu;
        //Time.timeScale = 0;
	}
	
	//Open the options panel
	public void openOptionsPanel()
	{
		escapePanel.gameObject.SetActive(false);
        optionsPanel.gameObject.SetActive(true);
        currentState = MenuStates.OptionsMenu;
	}
}
