using UnityEngine;
using System.Collections;
using UnityEditor;

[CustomEditor (typeof (MapGenerator))]
public class MapGeneratorEditor : Editor {

	public override void OnInspectorGUI() {
		MapGenerator mapGen = (MapGenerator)target;

		if (DrawDefaultInspector ()) {
			if (mapGen.autoUpdate) {
				mapGen.DrawMapInEditor ();
			}
		}

		if (GUILayout.Button ("Generate chunk in Editor")) {
			mapGen.DrawMapInEditor ();
		}

		if (GUILayout.Button ("Generate Map file")) {
			Map map = mapGen.GetComponent<Map>();
			map.changeLOD(3);
        }
	}
}
