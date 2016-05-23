using UnityEngine;
using System.Collections;

public class Deplacement : MonoBehaviour {

    public float speed;
    public float turnSpeed;

	// Use this for initialization
	void Start ()
    {
	    
	}

    // Update is called once per frame
    void FixedUpdate()
    {
        float h = Input.GetAxis("Horizontal");
        float v = Input.GetAxis("Vertical");

        Move(v);
        Turn(h);
    }

    void Update()
    {

    }

    void Move(float v)
    {
       // Debug.Log("j'avance de " + v);
        Vector3 movement = transform.forward * v * speed;
        GetComponent<Rigidbody>().MovePosition(transform.position + movement);
    }

    void Turn(float h)
    {
        float angle = turnSpeed * h;
        Quaternion q = Quaternion.Euler(0,angle,0);
        GetComponent<Rigidbody>().MoveRotation(transform.rotation * q);
    }
}
