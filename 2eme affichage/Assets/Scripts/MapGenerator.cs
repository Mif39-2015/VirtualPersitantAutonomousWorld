using UnityEngine;
using System;
using System.Collections;
using System.Linq;
using System.Collections.Generic;
using System.IO;

public class MapGenerator : MonoBehaviour {

	public enum DrawMode {NoiseMap, ColourMap, Mesh};
	public DrawMode drawMode;

	const int mapChunkSize = 241;
	//const int mapChunkSize = 51;
	[Range(0,6)]
	public int levelOfDetail;
	public float noiseScale;

	public int octaves;
	[Range(0,1)]
	public float persistance;
	public float lacunarity;

	public int seed;
	public Vector2 offset;

	public float meshHeightMultiplier;
	public AnimationCurve meshHeightCurve;

	public bool autoUpdate;

	public TerrainType[] regions;
	public bool WriteFile;
	public string FileName;
	public void GenerateMap() {
		float[,] noiseMap = Noise.GenerateNoiseMap (mapChunkSize, mapChunkSize, seed, noiseScale, octaves, persistance, lacunarity, offset);
		StreamWriter sw;
		sw = new StreamWriter (FileName,!WriteFile);
		float precision = 10;
		float echelle = 1 / precision;
		if (WriteFile) {
			sw.Write (mapChunkSize.ToString () + " ");
			sw.WriteLine (mapChunkSize.ToString ());
		}
		Color[] colourMap = new Color[mapChunkSize * mapChunkSize];
		for (int y = 0; y < mapChunkSize; y++) {
			for (int x = 0; x < mapChunkSize; x++) {
				float currentHeight = noiseMap [x, y];
				float h = echelle * Mathf.RoundToInt(currentHeight / echelle);
				if (WriteFile) 
				{
					sw.Write (x.ToString () + " " + y.ToString () + " ");				
					sw.Write (h.ToString () + " ");
				}
				for (int i = 0; i < regions.Length; i++) {
					if (currentHeight <= regions [i].height) {
						colourMap [y * mapChunkSize + x] = regions [i].colour;
						if(WriteFile)
							sw.WriteLine(regions [i].name);
						break;
					}
				}
			}
		}
		sw.Close ();
		MapDisplay display = FindObjectOfType<MapDisplay> ();
		if (drawMode == DrawMode.NoiseMap) {
			display.DrawTexture (TextureGenerator.TextureFromHeightMap (noiseMap));
		} else if (drawMode == DrawMode.ColourMap) {
			display.DrawTexture (TextureGenerator.TextureFromColourMap (colourMap, mapChunkSize, mapChunkSize));
		} else if (drawMode == DrawMode.Mesh) {
			display.DrawMesh (MeshGenerator.GenerateTerrainMesh (noiseMap, meshHeightMultiplier, meshHeightCurve, levelOfDetail), TextureGenerator.TextureFromColourMap (colourMap, mapChunkSize, mapChunkSize));
		}
	}

	void OnValidate() {
		if (lacunarity < 1) {
			lacunarity = 1;
		}
		if (octaves < 0) {
			octaves = 0;
		}
	}
}

[System.Serializable]
public struct TerrainType {
	public string name;
	public float height;
	public Color colour;
}