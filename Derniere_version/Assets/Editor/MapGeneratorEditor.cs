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
			Map map = new Map(mapGen, mapGen.mapSizeInChunk);
			map.test_write();
            //map.test_write_JSON();
        }
	}
}
