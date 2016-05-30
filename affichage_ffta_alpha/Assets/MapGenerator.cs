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

    public int mapSizeInChunk;

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

	public TerrainType[] regions;

	Queue<MapThreadInfo<MapData>> mapDataThreadInfoQueue = new Queue<MapThreadInfo<MapData>>();
	Queue<MapThreadInfo<MeshData>> meshDataThreadInfoQueue = new Queue<MapThreadInfo<MeshData>>();

	public void configure(MapGeneratorData mapGeneratorData) {
        this.noiseScale = mapGeneratorData.noiseScale;
        this.octaves = mapGeneratorData.octaves;
        this.persistance = mapGeneratorData.persistance;
        this.lacunarity = mapGeneratorData.lacunarity;
        this.seed = mapGeneratorData.seed;
        this.offset = mapGeneratorData.offset;
	}

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

	public void DrawMapInEditor(Map map) {

		GameObject chunkContainer = new GameObject("Chunks");

		Chunk[,] chunks = map.getMapChunks();
		int width = chunks.GetLength (0);
		int height = chunks.GetLength (1);

		for(int x = 0; x < width; ++x) {
			for(int y = 0; y < height; ++y) {
				Vector2 pos = chunks[x, y].getPosition() * MapGenerator.mapChunkSize;
				MapDisplay md = chunkContainer.AddComponent<MapDisplay>();
				GameObject plane = GameObject.CreatePrimitive(PrimitiveType.Plane);
				plane.transform.localScale = new Vector3(MapGenerator.mapChunkSize, 1, MapGenerator.mapChunkSize);
				plane.transform.localPosition = new Vector3(pos.x, 0, pos.y);
				md.transform.localPosition = new Vector3(pos.x, 0, pos.y);
				md.textureRender = plane.GetComponent<Renderer>();

				md.DrawTexture (TextureGenerator.TextureFromHeightMap (chunks[x, y].getHeightMap()));
			}
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

	MapData GenerateMapData(Vector2 centre) {
		float[,] noiseMap = Noise.GenerateNoiseMap (mapChunkSize, mapChunkSize, seed, noiseScale, octaves, persistance, lacunarity, centre + offset, normalizeMode);

		Color[] colourMap = new Color[mapChunkSize * mapChunkSize];
		for (int y = 0; y < mapChunkSize; y++) {
			for (int x = 0; x < mapChunkSize; x++) {
				float currentHeight = noiseMap [x, y];
				for (int i = 0; i < regions.Length; i++) {
					if (currentHeight >= regions [i].height) {
						colourMap [y * mapChunkSize + x] = regions [i].colour;
					} else {
						break;
					}
				}
			}
		}


		return new MapData (noiseMap, colourMap);
	}

	public ResourceEnum[,] generateResourcesFromNoiseMap(float[,] noiseMap) {
		ResourceEnum[,] resourceMap = new ResourceEnum[noiseMap.GetLength(0), noiseMap.GetLength(1)];

		//a modifier c'est pour tester là
		for(int x = 0; x < noiseMap.GetLength(0); ++x) {
			for(int y = 0; y < noiseMap.GetLength(1); ++y) {
				if(noiseMap[x, y] >= 0.7f && noiseMap[x, y] < 0.8f) {
					resourceMap[x, y] = ResourceEnum.Arbre;
				} else if(noiseMap[x, y] >= 0.5f && noiseMap[x, y] < 0.6f) {
					resourceMap[x, y] = ResourceEnum.Pierre;
				} else if(noiseMap[x, y] >= 0.1f && noiseMap[x, y] < 0.2f) {
					resourceMap[x, y] = ResourceEnum.Nourriture;
				} else resourceMap[x, y] = ResourceEnum.None;
			}
		}

		return resourceMap;
	}

	void OnValidate() {
		if (lacunarity < 1) {
			lacunarity = 1;
		}
		if (octaves < 0) {
			octaves = 0;
		}
        if (mapSizeInChunk < 1) {
            mapSizeInChunk = 1;
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
	public float height;
	public Color colour;
}

public struct MapData {
	public readonly float[,] heightMap;
//	public readonly ResourceEnum[,] resourceMap;
	public readonly Color[] colourMap;

	public MapData (float[,] heightMap, Color[] colourMap/*,ResourceEnum[,] resourceMap*/)
	{
		this.heightMap = heightMap;
//		this.resourceMap = resourceMap;
		this.colourMap = colourMap;
	}
}

public enum ResourceEnum {
		None,
		Arbre,
		Pierre,
		Nourriture,
		Metal
}
