using UnityEngine;
using System.Collections;
using UnityEngine.UI;

public class ChatBoxFunctions : MonoBehaviour {
	[SerializeField] ContentSizeFitter contentSizeFitter;
	[SerializeField] Text showHideButtonText;
	[SerializeField] Transform messageParentPanel;
	[SerializeField] GameObject newMessagePrefab;
	[SerializeField] InputField inputField;
	[SerializeField] GameObject scroll;

	bool isChatShowing = false;
	string message = "";
	private int limit = 30;
	private int msgs = 0;
	private float height = 0.0f;

	void Start () {
		ToggleChat ();
		scroll.transform.GetChild (1).transform.localScale = new Vector3(0, 0, 0);
		height = scroll.GetComponent<ScrollRect> ().content.rect.height;
	}

	void Update(){
		float currentheight = scroll.GetComponent<ScrollRect> ().content.rect.height;
		if ((currentheight - height) > 0.0) {
			scroll.GetComponent<ScrollRect> ().verticalScrollbar.value = 0;
			scroll.GetComponent<ScrollRect> ().verticalNormalizedPosition = 0;
			height = currentheight;
		}		
	}

	public void ToggleChat (){
		isChatShowing = !isChatShowing;
		scroll.SetActive (isChatShowing);
		if(isChatShowing){
			contentSizeFitter.verticalFit = ContentSizeFitter.FitMode.PreferredSize;
			showHideButtonText.text = "-";
		} else {
			contentSizeFitter.verticalFit = ContentSizeFitter.FitMode.MinSize;
			showHideButtonText.text = "+";

		}
	}

	public void SetMessage (string message){
		this.message = message;
	}

	public void ShowMessage (){
		if(message != ""){
			if (messageParentPanel.childCount == (limit)) {
				Destroy (messageParentPanel.GetChild (1).gameObject);
			}
			GameObject clone = (GameObject) Instantiate (newMessagePrefab);
			clone.transform.SetParent (messageParentPanel);
			clone.transform.SetSiblingIndex (messageParentPanel.childCount);
			clone.GetComponent<MessageFunctions>().ShowMessage (message);
			msgs++;
			if (msgs > 6) {
				scroll.transform.GetChild (1).transform.localScale = new Vector3(1, 1, 1);
			}
			inputField.Select();
			inputField.ActivateInputField();
			ScrollRect s = scroll.GetComponent<ScrollRect>();
		}
	}

	public void submit()
	{
		if (Input.GetButtonDown("Submit")){
			SetMessage (inputField.text);
			ShowMessage ();	
			inputField.text = "";
		}
	}
}