using UnityEngine;
using System.Collections;

public class CameraFollow : MonoBehaviour {

    
    public Transform target;
    private Vector3 offset;
    public float smoothing = 0.01f;
    public float speed;
    public float scrollSpeed = 0.2f;
    public float minZoom = 5.0f;
    public float maxZoom = 15.0f;
    public float scaleZoom = 0.9f;
    public NoScroll ns;


	// Use this for initialization
	void Start () {
        offset = transform.position - target.position;
        Cursor.visible = true;
        Camera camera = GetComponent<Camera>();
        ns.isOnRedZone = true;
	}
	
	// Update is called once per frame
	void FixedUpdate () {

        CamFollow();
       
    }
        
    void OnGui()
    {
        GUI.Box(new Rect(0, 0, Screen.width, Screen.height), "This is a box");

    }

    void CamFollow()
    {
        Vector2 mousePos;
        mousePos = Input.mousePosition; //We need to get the new position every frame
        
        if (ns.isOnRedZone)
        {
            // zoom
            if (Input.GetAxis("Mouse ScrollWheel") > 0 && Camera.main.orthographicSize > minZoom)
            {
                Camera.main.orthographicSize = Camera.main.orthographicSize - scaleZoom;
            }

            if (Input.GetAxis("Mouse ScrollWheel") < 0 && Camera.main.orthographicSize < maxZoom)
            {
                Camera.main.orthographicSize = Camera.main.orthographicSize + scaleZoom;
            }

            //if mouse is 50 pixels and less from the left side of the
            //screen, we move the camera in that direction at scrollSpeed
            if (mousePos.x < 50)
                gameObject.transform.Translate(-scrollSpeed, 0, 0);

            //if 50px or less from the right side, move right at scrollSpeeed
            if (mousePos.x > Screen.width - 50)
                gameObject.transform.Translate(scrollSpeed, 0, 0);

            //move up
            if (mousePos.y < 50)
                gameObject.transform.Translate(0, -scrollSpeed, 0);

            //move down
            if (mousePos.y > Screen.height - 50)
                gameObject.transform.Translate(0, scrollSpeed, 0);
        }

                   
    }
        
   
       
          
}

