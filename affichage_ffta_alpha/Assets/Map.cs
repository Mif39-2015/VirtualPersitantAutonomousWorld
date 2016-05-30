using UnityEngine;
using System;
using System.Collections;
using System.Runtime.Serialization;
using System.IO;
using MsgPack.Serialization;
using Newtonsoft.Json;

[Serializable]
public class Map {

	[JsonIgnore]
	[IgnoreDataMember]
    public MapGenerator mapGenerator;
    //pour la sérialistation

    [MessagePackMember(0)]
	[DataMember]
    public MapGeneratorData mapGeneratorData;
    //the map size in chunk
    [DataMember]
    [MessagePackMember(1)]
    public int mapSize;

    [MessagePackMember(2)]
    [DataMember]
    public Chunk[,] chunks;

	[JsonIgnore]
	[IgnoreDataMember]
    public GameObject chunkContainer;


    //rendering scale
    [JsonIgnore]
	[IgnoreDataMember]
    public const float scale = 10.0f;

    private int currentLOD = 0;

	//création a partir du MapGenerator, génération de toute la map dans le but de l'envoyer au server
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

	//création a partir d'un MapGeneratorData dans le but de recevoir les infos de la map du server
	public Map(MapGeneratorData mapGeneratorData, int mapSize) {
		mapGenerator = GameObject.FindObjectOfType<MapGenerator>();
		mapGenerator.configure(mapGeneratorData);

		this.mapGeneratorData = mapGeneratorData;
		this.mapSize= mapSize;

		chunkContainer = new GameObject("Terrain");

		chunks = new Chunk[mapSize, mapSize];
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

				float[,] resourceMapNoise = Noise.GenerateResourceNoise (mapGeneratorData.mapChunkSize,
                                            mapGeneratorData.mapChunkSize,
                                            mapGeneratorData.seed,
                                            mapGeneratorData.noiseScale,
											(center * mapGeneratorData.mapChunkSize) + mapGeneratorData.offset
											);
				ResourceEnum[,] resourceMap = mapGenerator.generateResourcesFromNoiseMap(resourceMapNoise);

				chunks[x, y] = new Chunk(this, center, heightMap, resourceMap);
			}
		}
	}

	public void test_write() {

       // MemoryStream stream = new MemoryStream();
        FileStream file = new FileStream("./test_map.map", FileMode.Truncate);

        MessagePackSerializer<Map> serializer = MessagePackSerializer.Get<Map>();
        serializer.Pack(file, this);
        file.Close();

        file = new FileStream("./test_map.map", FileMode.Open);
        Map map;
        map = serializer.Unpack(file);
//        map.debug();
        file.Close();

    }

   public void test_write_JSON()
    {
		//string json = JsonConvert.SerializeObject(this);
        // MemoryStream stream = new MemoryStream();
		/*string json = JsonConvert.SerializeObject(this, Formatting.Indented,
												new JsonSerializerSettings {
														ReferenceLoopHandling = ReferenceLoopHandling.Ignore
												});
		*/
        FileStream file = new FileStream("./test_map.json", FileMode.OpenOrCreate);
        StreamWriter writer = new StreamWriter(file);
		JsonTextWriter jsonWriter = new JsonTextWriter(writer);
		JsonSerializer ser = new JsonSerializer();
		ser.ReferenceLoopHandling = ReferenceLoopHandling.Ignore;
		ser.Formatting = Newtonsoft.Json.Formatting.Indented;
		ser.Serialize(jsonWriter, this);

        writer.Close();
        file.Close();


    }

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

	public void changeLOD(int newLOD) {
		if(newLOD < 0)
			newLOD = 0;
		else if(newLOD > 5)
			newLOD = 5;
		currentLOD = newLOD;
		updateChunks();
	}

	public void updateChunks() {
		for(int i = 0; i < mapSize; ++i) {
			for(int j = 0; j < mapSize; ++j) {
				chunks[i,j].UpdateChunk();
			}
		}
	}

	public int getCurrentLOD() {
		return currentLOD;
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
    [DataMember]
    public Vector2 position;
    [MessagePackMember(1)]
    [DataMember]
    public float[,] heightMap;
    [MessagePackMember(2)]
    [DataMember]
    public ResourceEnum[,] resourceMap;

	[JsonIgnore]
	[IgnoreDataMember]
    public ChunkMesh mesh;

	[JsonIgnore]
	[IgnoreDataMember]
    public Map map;

	public Chunk(Map map, Vector2 position, float[,] heightMap, ResourceEnum[,] resourceMap) {
		Debug.Log("Chunk constructor");
		this.map = map;
		this.position = position;
		this.heightMap = heightMap;
		this.resourceMap = resourceMap;

		mesh = new ChunkMesh(this, position, MapGenerator.mapChunkSize, map.chunkContainer.transform);
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

	public void UpdateChunk() {
		mesh.UpdateChunkMesh();
	}
}

public class ChunkMesh {
	GameObject meshObject;
	MeshRenderer meshRenderer;
	MeshFilter meshFilter;

	LODChunkMesh[] lodMeshes;

	Vector3 position;

	Chunk chunk;

	public ChunkMesh(Chunk chunk, Vector2 coord, int size, Transform parent) {
		Debug.Log("ChunkMesh constructor");
		this.chunk = chunk;

		Vector2 pos2D = coord * size;
		position = new Vector3(pos2D.x, 0, pos2D.y);

		meshObject = new GameObject("Terrain Chunk");
		meshRenderer = meshObject.AddComponent<MeshRenderer>();
		meshFilter = meshObject.AddComponent<MeshFilter>();

		meshObject.transform.position = position * Map.scale;
		meshObject.transform.parent = parent;
		meshObject.transform.localScale = Vector3.one * Map.scale;

		lodMeshes = new LODChunkMesh[6];
		for (int i = 0; i < 6; i++) {
			lodMeshes[i] = new LODChunkMesh(chunk.map.mapGenerator, i, UpdateChunkMesh);
		}


		MeshData meshData = MeshGenerator.GenerateTerrainMesh(	chunk.heightMap,
											chunk.map.mapGenerator.meshHeightMultiplier,
											chunk.map.mapGenerator.meshHeightCurve,
											0
										);
		meshFilter.mesh = meshData.CreateMesh();

		meshObject.SetActive (true);

		Debug.Log("pre updating");
		UpdateChunkMesh();

	}

	public void UpdateChunkMesh() {
		Debug.Log("updating");
		int lod = chunk.map.getCurrentLOD();
		LODChunkMesh lodMesh = lodMeshes[lod];

		if(lodMesh.hasMesh) {
			meshFilter.mesh = lodMesh.mesh;
			Debug.Log("updating 1");
		} else if (!lodMesh.hasRequestedMesh) {
			MapData mapData = new MapData(chunk.getHeightMap(), null);
			lodMesh.RequestMesh (mapData);
		}
		meshObject.SetActive(true);
	}

}

class LODChunkMesh {
	public Mesh mesh;
	public bool hasRequestedMesh;
	public bool hasMesh;
	int lod;

	public MapGenerator mapGenerator;

	System.Action updateCallback;

	public LODChunkMesh(MapGenerator mapGen, int lod, System.Action updateCallback) {
		Debug.Log("LODMesh constructor");
		this.mapGenerator = mapGen;
		this.lod = lod + 1;
		this.updateCallback = updateCallback;
		this.hasMesh = false;
		hasRequestedMesh = false;
	}

	void OnMeshDataReceived(MeshData meshData) {
		mesh = meshData.CreateMesh ();
		hasMesh = true;
		updateCallback ();
	}

	public void RequestMesh(MapData mapData) {
		hasRequestedMesh = true;
		mapGenerator.RequestMeshData (mapData, lod, OnMeshDataReceived);
	}
}
