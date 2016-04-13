using UnityEngine;
using System.Collections;

public static class MeshGenerator {

	public static MeshData GenerateTerrainMesh(float[,] heightMap, float heightMultiplier, AnimationCurve _heightCurve, int levelOfDetail) {
		AnimationCurve heightCurve = new AnimationCurve (_heightCurve.keys);

		float tileSize = 1.0f;
		int width = heightMap.GetLength (0);
		int height = heightMap.GetLength (1);
		float topLeftX = (width - 1) / -2f;
		float topLeftZ = (height - 1) / 2f;

		int meshSimplificationIncrement = (levelOfDetail == 0)?1:levelOfDetail * 2;
		int verticesPerLine = (width - 1) / meshSimplificationIncrement + 1;

		MeshData meshData = new MeshData (verticesPerLine, verticesPerLine);
		int vertexIndex = 0;

		for (int y = 0; y < height; y += meshSimplificationIncrement) {
			for (int x = 0; x < width; x += meshSimplificationIncrement) {

				float sum = 0.0f;
				float count = 0;
				for(int i = x; i < x + meshSimplificationIncrement; ++i) {
					for(int j = y; j < y + meshSimplificationIncrement; ++j) {
						sum += heightCurve.Evaluate (heightMap [i, j]) * heightMultiplier;
						++count;
					}
				}
				float avr_height = sum / count;

				meshData.vertices [vertexIndex]     = new Vector3 (topLeftX + x - tileSize / 2, avr_height, topLeftZ - y + tileSize / 2);
				meshData.vertices [vertexIndex + 1] = new Vector3 (topLeftX + x +  (meshSimplificationIncrement - 1) * tileSize + tileSize / 2, avr_height, topLeftZ - y + tileSize / 2);
				meshData.vertices [vertexIndex + 2] = new Vector3 (topLeftX + x +  (meshSimplificationIncrement - 1) * tileSize + tileSize / 2, avr_height, topLeftZ - y - (meshSimplificationIncrement - 1) * tileSize - tileSize / 2);
				meshData.vertices [vertexIndex + 3] = new Vector3 (topLeftX + x - tileSize / 2, avr_height, topLeftZ - y - (meshSimplificationIncrement - 1) * tileSize - tileSize / 2);

				meshData.uvs [vertexIndex] = new Vector2 (x / (float)width, y / (float)height);
				meshData.uvs [vertexIndex + 1] = new Vector2 (x / (float)width, y / (float)height);
				meshData.uvs [vertexIndex + 2] = new Vector2 (x / (float)width, y / (float)height);
				meshData.uvs [vertexIndex + 3] = new Vector2 (x / (float)width, y / (float)height);

				//if (x < width - 1 && y < height - 1) {
				meshData.AddTriangle (vertexIndex, vertexIndex + 1, vertexIndex + 2);
				meshData.AddTriangle (vertexIndex + 2, vertexIndex + 3, vertexIndex);
				//}

				//meshData.AddTriangle (vertexIndex, vertexIndex + 3, vertexIndex + 2);
				//meshData.AddTriangle (vertexIndex, vertexIndex + 2, vertexIndex + 1);

				//Faudra faire gaffe aux bords à droite et en bas
				//droite
				if(x < width - meshSimplificationIncrement)
				{
					meshData.AddTriangle (vertexIndex + 2, vertexIndex + 1, vertexIndex + 4);
					meshData.AddTriangle (vertexIndex + 4, vertexIndex + 7, vertexIndex + 2);
				}
				if(y < height - meshSimplificationIncrement) {
					meshData.AddTriangle (vertexIndex + 3, vertexIndex + 2, vertexIndex + verticesPerLine*4 + 1);
					meshData.AddTriangle (vertexIndex + verticesPerLine*4 + 1, vertexIndex + verticesPerLine*4, vertexIndex + 3);
				}
				/*
				if(x < width - meshSimplificationIncrement)
				{
					meshData.AddTriangle (vertexIndex + 2, vertexIndex + 7, vertexIndex + 4);
					meshData.AddTriangle (vertexIndex + 2, vertexIndex + 4, vertexIndex + 1);
				}
				if(y < height - meshSimplificationIncrement) {
					meshData.AddTriangle (vertexIndex + 3, vertexIndex + verticesPerLine*4, vertexIndex + verticesPerLine*4 + 1);
					meshData.AddTriangle (vertexIndex + 3, vertexIndex + verticesPerLine*4 + 1, vertexIndex + 2);
				}*/

				vertexIndex += 4;
			}
		}

		return meshData;

	}
}

public class MeshData {
	public Vector3[] vertices;
	public int[] triangles;
	public Vector2[] uvs;

	int triangleIndex;

	public MeshData(int meshWidth, int meshHeight) {
		vertices = new Vector3[meshWidth * meshHeight * 4];
		uvs = new Vector2[meshWidth * meshHeight * 4];
		triangles = new int[(meshWidth)*(meshHeight)* 6 * 3];
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
