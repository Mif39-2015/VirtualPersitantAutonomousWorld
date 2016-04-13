﻿using UnityEngine;
using System.Collections;

public class spielberg : MonoBehaviour {

    public float minFov = 15f;
    public float maxFov  = 200f;
    public float sensitivity  = 10f;
    

    void Update()
    {
        float fov = Camera.main.fieldOfView;
        fov -= Input.GetAxis("Mouse ScrollWheel") * sensitivity;
        fov = Mathf.Clamp(fov, minFov, maxFov);
        Camera.main.fieldOfView = fov;
    }
}