using UnityEngine;
using System.Collections;

public static class MeshGenerator 
{
	static AnimationCurve 	heightCurve;
	static float          	tileSize;
	static int          	width;
	static int 		   		height;
	static float 			topLeftX;
	static float 			topLeftZ;
	static int 				meshSimplificationIncrement;
	static int 				verticesPerLine;
	static MeshData 		meshData;
	static int 				vertexIndex;
	static float[,]			heightMap;
	static float            heightMultiplier;

	public static MeshData GenerateTerrainMesh(float[,] _heightMap, float _heightMultiplier, AnimationCurve _heightCurve, int levelOfDetail, Texture2D biomes) 
	{
		//initialisation
		heightCurve 				= new AnimationCurve (_heightCurve.keys);
		tileSize 					= 1.0f;
		width 						= _heightMap.GetLength (0);
		height 						= _heightMap.GetLength (1);
		topLeftX 					= (width - 1) / -2f;
		topLeftZ 					= (height - 1) / 2f;
		meshSimplificationIncrement = (int) Mathf.Pow (2, levelOfDetail);//(levelOfDetail == 0)?1:levelOfDetail * 2;
		verticesPerLine 			= (width - 1) / meshSimplificationIncrement + 1;
		meshData 					= new MeshData (verticesPerLine, verticesPerLine);
		vertexIndex 				= 0;
		heightMap					= _heightMap;
		heightMultiplier 			= _heightMultiplier;

		int y = 0;
		int x = 0;
		//On parcourt toutes les tildes que l'on va dessiner
		for (y = 0; y < height; y += meshSimplificationIncrement) 
		{
			float avr_height = get_height(0, y, 0, y);
			for (x = 0; x < width; x += meshSimplificationIncrement) 
			{
				float avr_height_droite = get_height(x, y, x + meshSimplificationIncrement, y);
				float decallage = Mathf.Abs((avr_height%meshSimplificationIncrement)/meshSimplificationIncrement);

				//
				//Placage des points
				//
				// 0--------1/5
				//  \     X  |\            coordonnées de X : new Vector3 (topLeftX + x, avr_height, topLeftZ - y);
				//   \       | \
				//   3/8-----|--2/4/9
				//   |       |   |  
				//   |       6   |
				//   |        \  |
				//   |         \ |   
				//   11--------7/10

				//
				//Dessus
				//
				//Poins
				meshData.vertices [vertexIndex]      = new Vector3 (topLeftX + x - tileSize / 2, 
				                                                   avr_height, 
				                                                   topLeftZ - y + tileSize / 2);
				meshData.vertices [vertexIndex + 1]  = new Vector3 (topLeftX + x +  (meshSimplificationIncrement - 1) * tileSize + tileSize / 2, 
				                                                   avr_height, 
				                                                   topLeftZ - y + tileSize / 2);
				meshData.vertices [vertexIndex + 2]  = new Vector3 (topLeftX + x +  (meshSimplificationIncrement - 1) * tileSize + tileSize / 2, 
				                                                   avr_height, 
				                                                   topLeftZ - y - (meshSimplificationIncrement - 1) * tileSize - tileSize / 2);
				meshData.vertices [vertexIndex + 3]  = new Vector3 (topLeftX + x - tileSize / 2, 
				                                                   avr_height, 
				                                                   topLeftZ - y - (meshSimplificationIncrement - 1) * tileSize - tileSize / 2);

				//Triangles
				meshData.AddTriangle (vertexIndex, vertexIndex + 1, vertexIndex + 2);
				meshData.AddTriangle (vertexIndex + 2, vertexIndex + 3, vertexIndex);

				//Textures
				Color pixel = biomes.GetPixel(x,y);
				if((pixel.r == 1) && (pixel.g == 1) && (pixel.b == 1))//Neige
				{
					meshData.uvs [vertexIndex + 0] = new Vector2 (0.66f, 0);
					meshData.uvs [vertexIndex + 1] = new Vector2 (0.66f, 1);
					meshData.uvs [vertexIndex + 2] = new Vector2 (1, 1);
					meshData.uvs [vertexIndex + 3] = new Vector2 (1, 0);
				}
				else
				{
					meshData.uvs [vertexIndex + 0] = new Vector2 (0.33f, 0);
					meshData.uvs [vertexIndex + 1] = new Vector2 (0.33f, 1);
					meshData.uvs [vertexIndex + 2] = new Vector2 (0.66f, 1);
					meshData.uvs [vertexIndex + 3] = new Vector2 (0.66f, 0);
				}

				//
				//Droite
				//
				if(x < width - meshSimplificationIncrement)
				{
					//Points
					meshData.vertices [vertexIndex + 4]  = meshData.vertices [vertexIndex + 2];
					meshData.vertices [vertexIndex + 5]  = meshData.vertices [vertexIndex + 1];
					meshData.vertices [vertexIndex + 6]  = new Vector3 (meshData.vertices [vertexIndex + 5].x, 
					                                                    avr_height_droite, 
					                                                    meshData.vertices [vertexIndex + 5].z);
					meshData.vertices [vertexIndex + 7]  = new Vector3 (meshData.vertices [vertexIndex + 4].x, 
					                                                    avr_height_droite, 
					                                                    meshData.vertices [vertexIndex + 4].z);

					//Triangles
					meshData.AddTriangle (vertexIndex + 4, vertexIndex + 5, vertexIndex + 6);
					meshData.AddTriangle (vertexIndex + 6, vertexIndex + 7, vertexIndex + 4);

					//Textures
					float distance = Mathf.Abs(avr_height - avr_height_droite);
					float taille_tile = Mathf.Abs(meshData.vertices [vertexIndex].x - meshData.vertices [vertexIndex + 1].x);
					float proportion = distance/taille_tile;
					meshData.uvs [vertexIndex + 4] = new Vector2 (0.0f, -decallage);
					meshData.uvs [vertexIndex + 5] = new Vector2 (0.33f, -decallage);
					meshData.uvs [vertexIndex + 6] = new Vector2 (0.33f, -decallage + proportion);
					meshData.uvs [vertexIndex + 7] = new Vector2 (0.0f, -decallage + proportion);
				}

				//
				//Bas
				//
				if(y < height - meshSimplificationIncrement)
				{
					float avr_height_bas = get_height(x, y, x, y + meshSimplificationIncrement);
					float distance = Mathf.Abs(avr_height - avr_height_bas);
					float taille_tile = Mathf.Abs(meshData.vertices [vertexIndex].x - meshData.vertices [vertexIndex + 1].x);
					float proportion = distance/taille_tile;

					meshData.vertices [vertexIndex + 8]  = meshData.vertices [vertexIndex + 3];
					meshData.vertices [vertexIndex + 9]  = meshData.vertices [vertexIndex + 2];
					meshData.vertices [vertexIndex + 10] = new Vector3 (meshData.vertices [vertexIndex + 9].x, 
					                                                    avr_height_bas, 
					                                                    meshData.vertices [vertexIndex + 9].z);
					meshData.vertices [vertexIndex + 11] = new Vector3 (meshData.vertices [vertexIndex + 8].x, 
					                                                    avr_height_bas, 
					                                                    meshData.vertices [vertexIndex + 8].z);
					meshData.AddTriangle (vertexIndex + 8, vertexIndex + 9, vertexIndex + 10);
					meshData.AddTriangle (vertexIndex + 10, vertexIndex + 11, vertexIndex + 8);
					meshData.uvs [vertexIndex + 8] = new Vector2 (0.0f, decallage);
					meshData.uvs [vertexIndex + 9] = new Vector2 (0.33f, decallage);
					meshData.uvs [vertexIndex + 10] = new Vector2 (0.33f, decallage + proportion);
					meshData.uvs [vertexIndex + 11] = new Vector2 (0.0f, decallage + proportion);
				}

				vertexIndex += 12;

				avr_height = avr_height_droite;
			}
		}

		return meshData;
	}

	private static int get_height(int x, int y, int start_x, int start_y)
	{
		float sum = 0.0f;
		int count = 0;

		int end_x = start_x + meshSimplificationIncrement;
		int end_y = start_y + meshSimplificationIncrement;

		if(end_x > width)  end_x = width;
		if(end_y > height) end_y = height;
		
		for(int i = start_x; i < end_x; ++i) 
		{
			for(int j = start_y; j < end_y; ++j) 
			{
				sum += heightCurve.Evaluate (heightMap [i, j]) * heightMultiplier;
				++count;
			}
		}

		return (int) ((sum / count) * 100);
	}
}

public class MeshData {
	public Vector3[] vertices;
	public int[] triangles;
	public Vector2[] uvs;

	int triangleIndex;

	public MeshData(int meshWidth, int meshHeight) {
		vertices = new Vector3[meshWidth * meshHeight * 4 * 3];
		uvs = new Vector2[meshWidth * meshHeight * 4 * 3];
		triangles = new int[(meshWidth)*(meshHeight)* 6 * 3 * 3];
	}

	public void AddTriangle(int a, int b, int c) {
		triangles [triangleIndex] = a;
		triangles [triangleIndex + 1] = b;
		triangles [triangleIndex + 2] = c;
		triangleIndex += 3;
	}

	public Mesh CreateMesh() {
		Mesh mesh = new Mesh ();
		mesh.vertices = vertices;
		mesh.triangles = triangles;
		mesh.uv = uvs;
		mesh.RecalculateNormals ();
		return mesh;
	}

}
