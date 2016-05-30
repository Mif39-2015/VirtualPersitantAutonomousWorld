using UnityEngine;
using System.Collections;
using System;
using System.Threading;
using System.Collections.Generic;

public class MapGenerator : MonoBehaviour {

	public enum DrawMode {NoiseMap, ColourMap, Mesh};
	public DrawMode drawMode;

	public Noise.NormalizeMode normalizeMode;

	public const int mapChunkSize = 64;
	[Range(0,6)]
	public int editorPreviewLOD;
	public float noiseScale;
	[Range(1,100)]
	public int echelle;

	public int octaves;
	[Range(0,1)]
	public float persistance;
	public float lacunarity;

	public int seed;
	public Vector2 offset;

	public float meshHeightMultiplier;
	public AnimationCurve meshHeightCurve;

	public bool autoUpdate;

	public TerrainType water;

	public Biome[] biomes;

//	public TerrainType[] regions;

	Queue<MapThreadInfo<MapData>> mapDataThreadInfoQueue = new Queue<MapThreadInfo<MapData>>();
	Queue<MapThreadInfo<MeshData>> meshDataThreadInfoQueue = new Queue<MapThreadInfo<MeshData>>();


	public void DrawMapInEditor() {
		MapData mapData = GenerateMapData (Vector2.zero);

		MapDisplay display = FindObjectOfType<MapDisplay> ();
		if (drawMode == DrawMode.NoiseMap) {
			display.DrawTexture (TextureGenerator.TextureFromHeightMap (mapData.heightMap));
		} else if (drawMode == DrawMode.ColourMap) {
			display.DrawTexture (TextureGenerator.TextureFromColourMap (mapData.colourMap, mapChunkSize, mapChunkSize));
		} else if (drawMode == DrawMode.Mesh) {
			display.DrawMesh (MeshGenerator.GenerateTerrainMesh (mapData.heightMap, meshHeightMultiplier, meshHeightCurve, editorPreviewLOD), TextureGenerator.TextureFromColourMap (mapData.colourMap, mapChunkSize, mapChunkSize));
		}
	}

	public void RequestMapData(Vector2 centre, Action<MapData> callback) {
		ThreadStart threadStart = delegate {
			MapDataThread (centre, callback);
		};

		new Thread (threadStart).Start ();
	}

	void MapDataThread(Vector2 centre, Action<MapData> callback) {
		MapData mapData = GenerateMapData (centre);
		lock (mapDataThreadInfoQueue) {
			mapDataThreadInfoQueue.Enqueue (new MapThreadInfo<MapData> (callback, mapData));
		}
	}

	public void RequestMeshData(MapData mapData, int lod, Action<MeshData> callback) {
		ThreadStart threadStart = delegate {
			MeshDataThread (mapData, lod, callback);
		};

		new Thread (threadStart).Start ();
	}

	void MeshDataThread(MapData mapData, int lod, Action<MeshData> callback) {
		MeshData meshData = MeshGenerator.GenerateTerrainMesh (mapData.heightMap, meshHeightMultiplier, meshHeightCurve, lod);
		lock (meshDataThreadInfoQueue) {
			meshDataThreadInfoQueue.Enqueue (new MapThreadInfo<MeshData> (callback, meshData));
		}
	}

	void Update() {
		if (mapDataThreadInfoQueue.Count > 0) {
			for (int i = 0; i < mapDataThreadInfoQueue.Count; i++) {
				MapThreadInfo<MapData> threadInfo = mapDataThreadInfoQueue.Dequeue ();
				threadInfo.callback (threadInfo.parameter);
			}
		}

		if (meshDataThreadInfoQueue.Count > 0) {
			for (int i = 0; i < meshDataThreadInfoQueue.Count; i++) {
				MapThreadInfo<MeshData> threadInfo = meshDataThreadInfoQueue.Dequeue ();
				threadInfo.callback (threadInfo.parameter);
			}
		}
	}

	// 0 parcouru, 1 en cours, 2 parcouru
	int[,] mapParcourue = new int[mapChunkSize, mapChunkSize];


	// initialisation du parcours de la noisemap
	void parcourue(float[,] noiseMap){
		int cptBiomes = 0;
		Queue<Vector2> fileDatt = new Queue<Vector2>(); 
		//init 
		for (int y = 0; y < mapChunkSize; y++) {
			for (int x = 0; x < mapChunkSize; x++) {
				if (noiseMap[x,y] < 0) {// si c'est de l'eau, on ne traite pas 
					mapParcourue[x,y] = 2;
				}
			}
		}
		// sinon on va ajouter les pixels et ses voisins dans une liste d'attente 
		for (int y = 0; y < mapChunkSize; y++) {
			for (int x = 0; x < mapChunkSize; x++) {

				if(mapParcourue[x,y] < 2){ // si ca n'a pas été parcouru (ou ca n'est pas de l'eau)
					fileDatt.Enqueue (new Vector2 (x, y));
					mapParcourue [x, y] = 1; // gris
					// test voisins
					while (fileDatt.Count != 0) {
						Vector2 pos = fileDatt.Dequeue ();
						if (1) {
						
						}
					}
				}
			
			}
		}

	}


	void decoupageMap(){

	}


	                  

	MapData GenerateMapData(Vector2 centre) {

		float[,] noiseMap = Noise.GenerateNoiseMap (mapChunkSize, mapChunkSize, seed, noiseScale, octaves, persistance, lacunarity, centre + offset, normalizeMode, echelle);

		Color[] colourMap = new Color[mapChunkSize * mapChunkSize];

		// boucle coloriage
		for (int y = 0; y < mapChunkSize; y++) {
			for (int x = 0; x < mapChunkSize; x++) {
				float currentHeight = noiseMap [x, y];
				if (currentHeight >= water.height){
					colourMap [y * mapChunkSize + x] = water.colour;
				}
				for (int i = 0; i < biomes[0].regionsDuBiome.Length; i++) {
					if (currentHeight >= biomes[0].regionsDuBiome [i].height) {
							colourMap [y * mapChunkSize + x] = biomes[0].regionsDuBiome [i].colour;
					} 
					else {
						break;
					}
				}

			}
		}
		return new MapData (noiseMap, colourMap);
	}

	void OnValidate() {
		if (lacunarity < 1) {
			lacunarity = 1;
		}
		if (octaves < 0) {
			octaves = 0;
		}
	}

	struct MapThreadInfo<T> {
		public readonly Action<T> callback;
		public readonly T parameter;

		public MapThreadInfo (Action<T> callback, T parameter)
		{
			this.callback = callback;
			this.parameter = parameter;
		}
	}


}

[System.Serializable]
public struct TerrainType {
	public string name;
	public float height; // mini + de 0 car water définie avant
	public Color colour;
	//public Transform texture; pour plus tard
}

[System.Serializable]
public struct Biome {
	public string name;
	public AnimationCurve allureBiome;
	public TerrainType[] regionsDuBiome;
	Vector2[] coordMap;


}

public struct MapData {
	public readonly float[,] heightMap;
	public readonly Color[] colourMap;

	public MapData (float[,] heightMap, Color[] colourMap)
	{
		this.heightMap = heightMap;
		this.colourMap = colourMap;
	}
}
