using UnityEngine;
using System.Collections;
using UnityEngine.UI;

public class ChatBoxFunctions : MonoBehaviour {
	[SerializeField] ContentSizeFitter contentSizeFitter;
	[SerializeField] Text showHideButtonText;
	[SerializeField] Transform messageParentPanel;
	[SerializeField] GameObject newMessagePrefab;

	bool isChatShowing = false;
	string message = "";

	void Start () {
		ToggleChat ();
	}

	public void ToggleChat (){
		isChatShowing = !isChatShowing;
		if(isChatShowing){
			contentSizeFitter.verticalFit = ContentSizeFitter.FitMode.PreferredSize;
			showHideButtonText.text = "Cacher Chat";
		} else {
			contentSizeFitter.verticalFit = ContentSizeFitter.FitMode.MinSize;
			showHideButtonText.text = "Afficher Chat";
		}
	}

	public void SetMessage (string message){
		this.message = message;
	}

	public void ShowMessage (){
		if(message != ""){
			GameObject clone = (GameObject) Instantiate (newMessagePrefab);
			clone.transform.SetParent (messageParentPanel);
			clone.transform.SetSiblingIndex (messageParentPanel.childCount - 2);
			clone.GetComponent<MessageFunctions>().ShowMessage (message);
		}
	}
}