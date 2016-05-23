using UnityEngine;
using System.Collections;
using UnityEngine.UI;

public class dropdownsimple : MonoBehaviour {

	public RectTransform container;
	public bool IsOpen;

	// Use this for initialization
	void Start () {
		Button myButton = GetComponent<Button>();
		myButton.onClick.AddListener(inverseOpen);
		container = transform.FindChild("container").GetComponent<RectTransform>();
		IsOpen = false;
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
	}
}
