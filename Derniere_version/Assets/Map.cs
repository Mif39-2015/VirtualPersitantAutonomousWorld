using UnityEngine;
using System;
using System.Collections;
using System.Runtime.Serialization;
using System.IO;
using MsgPack.Serialization;

[Serializable]
public class Map {

    public MapGenerator mapGenerator;
    //pour la sérialistation
    [MessagePackMember(0)]
    public MapGeneratorData mapGeneratorData;
    //the map size in chunk
    [MessagePackMember(1)]
    public int mapSize;
    [MessagePackMember(2)]
    public Chunk[,] chunks;

    public GameObject chunkContainer;


    //rendering scale
    public const float scale = 10.0f;

	public Map(MapGenerator mapGenerator, int mapSize) {
		this.mapGenerator = mapGenerator;
		this.mapSize = mapSize;
        mapGeneratorData = new MapGeneratorData();

        mapGeneratorData.mapChunkSize = MapGenerator.mapChunkSize;
        mapGeneratorData.noiseScale = mapGenerator.noiseScale;
        mapGeneratorData.octaves = mapGenerator.octaves;
        mapGeneratorData.persistance = mapGenerator.persistance;
        mapGeneratorData.lacunarity = mapGenerator.lacunarity;
        mapGeneratorData.seed = mapGenerator.seed;
        mapGeneratorData.offset = mapGenerator.offset;


		chunkContainer = new GameObject("Terrain");

        //Debug.Log("generating map");
        generateChunks();
	}

    //necessaire pour la sérialisation
    public Map()
    {
    }


    private void generateChunks() {
        if(mapGenerator == null)
        {
            mapGenerator = GameObject.FindObjectOfType<MapGenerator>();
        }
		chunks = new Chunk[mapSize, mapSize];
		float halfSize = (mapSize - 1) / 2.0f;
		Vector2 center = Vector2.zero;

		for(int x = 0; x < mapSize; ++x) {
			for(int y = 0; y < mapSize; ++y) {
				float offsetX = x - halfSize;
				float offsetY = y - halfSize;

				center.x = offsetX;
				center.y = offsetY;
				//Debug.Log("generating chunk");
				float[,] heightMap = Noise.GenerateNoiseMap (mapGeneratorData.mapChunkSize,
                                            mapGeneratorData.mapChunkSize,
                                            mapGeneratorData.seed,
                                            mapGeneratorData.noiseScale,
                                            mapGeneratorData.octaves,
                                            mapGeneratorData.persistance,
                                            mapGeneratorData.lacunarity,
											(center * mapGeneratorData.mapChunkSize) + mapGeneratorData.offset,
											mapGenerator.normalizeMode);

				chunks[x, y] = new Chunk(this, center, heightMap, mapGenerator.texture, mapGenerator.biomes);
			}
		}
	}

	public void test_write() {

       // MemoryStream stream = new MemoryStream();
        FileStream file = new FileStream("./test_map.map", FileMode.Create);

        MessagePackSerializer<Map> serializer = MessagePackSerializer.Get<Map>();
        serializer.Pack(file, this);
        file.Close();

        file = new FileStream("./test_map.map", FileMode.Open);
        Map map;
        map = serializer.Unpack(file);
        //map.debug();
        file.Close();

    }

   /*public void test_write_JSON()
    {

        // MemoryStream stream = new MemoryStream();
        FileStream file = new FileStream("./test_map.json", FileMode.OpenOrCreate);
        StreamWriter writer = new StreamWriter(file);

        string json = JsonUtility.ToJson(this);
        writer.Write(json);
        writer.Close();
        file.Close();

    }*/

    public void debug()
    {
        if(mapGenerator == null)
            Debug.Log("MAP GENERATOR IS NULL !!");
        float[,] hm = chunks[0, 0].getHeightMap();
        Vector2 chunk_coord = chunks[0, 0].getPosition();
        Debug.Log("chunk coord: x=" + chunk_coord.x + " y=" + chunk_coord.y);
        for (int x = 0; x < hm.GetLength (0); ++x) {
			Debug.Log(hm[x,0]);
		}
    }

    public Chunk[,] getMapChunks() {
		return chunks;
	}
}

[Serializable]
public class MapGeneratorData
{
    public MapGeneratorData() { }
    [MessagePackMember(0)]
    public int mapChunkSize;
    [MessagePackMember(1)]
    public float noiseScale;
    [MessagePackMember(2)]
    public int octaves;
    [MessagePackMember(3)]
    public float persistance;
    [MessagePackMember(4)]
    public float lacunarity;
    [MessagePackMember(5)]
    public int seed;
    [MessagePackMember(6)]
    public Vector2 offset;

}

[Serializable]
public class Chunk {

    [MessagePackMember(0)]
    public Vector2 position;
    [MessagePackMember(1)]
    public float[,] heightMap;

    public ChunkMesh mesh;

    public Map map;

	public Chunk(Map map, Vector2 position, float[,] heightMap, Texture2D texture, Texture2D biomes) {
		this.map = map;
		this.position = position;
		this.heightMap = heightMap;

		mesh = new ChunkMesh(this, position, MapGenerator.mapChunkSize, map.chunkContainer.transform, texture, biomes);
	}

    //necessaire pour la sérialisation
    public Chunk()
    {
    }

    public float[,] getHeightMap() {
		return heightMap;
	}

	public Vector2 getPosition() {
		return position;
	}
}

public class ChunkMesh {
	GameObject meshObject;
	MeshRenderer meshRenderer;
	MeshFilter meshFilter;

	Vector3 position;

	Chunk chunk;

	public ChunkMesh(Chunk chunk, Vector2 coord, int size, Transform parent, Texture2D texture, Texture2D biomes) {
		this.chunk = chunk;

		Vector2 pos2D = coord * size;
		position = new Vector3(pos2D.x, 0, pos2D.y);

		meshObject = new GameObject("Terrain Chunk");
		meshObject.AddComponent<MeshRenderer>();
		meshRenderer = meshObject.GetComponent<MeshRenderer>();
		meshObject.AddComponent<MeshFilter>();
		meshFilter = meshObject.GetComponent<MeshFilter>();

		meshObject.transform.position = position * Map.scale;
		meshObject.transform.parent = parent;
		meshObject.transform.localScale = Vector3.one * Map.scale;

		MeshData meshData = MeshGenerator.GenerateTerrainMesh(	chunk.heightMap,
											chunk.map.mapGenerator.meshHeightMultiplier,
											chunk.map.mapGenerator.meshHeightCurve,
											0,
		                                    biomes
										);

		//meshFilter.mesh = meshData.CreateMesh();



		meshFilter.mesh = meshData.CreateMesh ();
		Texture2D t = Resources.Load("test 1.tga") as Texture2D;//texture;///////////////////////////////////
		//meshRenderer.sharedMaterial.mainTexture = t;
		//meshRenderer.material.color = Color.green;
		//meshRenderer.sharedMaterial.color = Color.green;
		meshRenderer.material.mainTexture = texture;

		meshObject.SetActive (true);


	}

}

//public class
