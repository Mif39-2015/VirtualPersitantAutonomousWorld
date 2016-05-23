using UnityEngine;
using System.Collections;
using System;


    class Wedge : MonoBehaviour ,IComparable<Wedge>

    {
       public float fill;

       public int CompareTo(Wedge other)
       {
           return other.fill.CompareTo(this.fill);
       }

    }

