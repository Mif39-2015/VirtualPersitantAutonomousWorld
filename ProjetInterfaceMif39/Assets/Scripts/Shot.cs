using UnityEngine;
using System.Collections;

public class Shot : MonoBehaviour {

	
	// Update is called once per frame
	void Update () {
        if (Input.GetButtonDown("Jump"))
        {
            // Debug.Log("Jump !");
            Fire();
        }
	}

    void Fire()
    {
        Debug.Log("tire !");
    }
}
