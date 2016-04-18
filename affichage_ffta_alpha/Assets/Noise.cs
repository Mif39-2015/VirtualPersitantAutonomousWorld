using UnityEngine;
using System.Collections;

public static class Noise {

	public enum NormalizeMode {Local, Global};

	public static float[,] GenerateNoiseMap(int mapWidth, int mapHeight, int seed, float scale, int octaves, float persistance, float lacunarity, Vector2 offset, NormalizeMode normalizeMode) {
		float[,] noiseMap = new float[mapWidth,mapHeight];
	//Debug.Log("x: "+ offset.x + "y:" + offset.y);
	//Debug.Log("mapWidth: "+ mapWidth + "mapHeight:" + mapHeight);
		System.Random prng = new System.Random (seed);
		Vector2[] octaveOffsets = new Vector2[octaves];

		float maxPossibleHeight = 0;
		float amplitude = 1;
		float frequency = 1;

		for (int i = 0; i < octaves; i++) {
			float offsetX = prng.Next (-100000, 100000) + offset.x;
			float offsetY = prng.Next (-100000, 100000) - offset.y;
			octaveOffsets [i] = new Vector2 (offsetX, offsetY);

			maxPossibleHeight += amplitude;
			amplitude *= persistance;
		}

		if (scale <= 0) {
			scale = 0.0001f;
		}

		float maxLocalNoiseHeight = float.MinValue;
		float minLocalNoiseHeight = float.MaxValue;

		float halfWidth = mapWidth / 2f;
		float halfHeight = mapHeight / 2f;


		for (int y = 0; y < mapHeight; y++) {
			for (int x = 0; x < mapWidth; x++) {

				amplitude = 1;
				frequency = 1;
				float noiseHeight = 0;

				for (int i = 0; i < octaves; i++) {
					float sampleX = (x-halfWidth + octaveOffsets[i].x) / scale * frequency;
					float sampleY = (y-halfHeight + octaveOffsets[i].y) / scale * frequency;

					float perlinValue = Mathf.PerlinNoise (sampleX, sampleY) * 2 - 1;
					noiseHeight += perlinValue * amplitude;

					amplitude *= persistance;
					frequency *= lacunarity;
				}

				if (noiseHeight > maxLocalNoiseHeight) {
					maxLocalNoiseHeight = noiseHeight;
				} else if (noiseHeight < minLocalNoiseHeight) {
					minLocalNoiseHeight = noiseHeight;
				}
				noiseMap [x, y] = noiseHeight;
			}
		}

		float precision = 100;
		float echelle = 1;

		for (int y = 0; y < mapHeight; y++) {
			for (int x = 0; x < mapWidth; x++) {
				if (normalizeMode == NormalizeMode.Local) {
					noiseMap [x, y] = Mathf.InverseLerp (minLocalNoiseHeight, maxLocalNoiseHeight, noiseMap [x, y]);
					int val = (int) (noiseMap[x, y] * precision);
					//Debug.Log("val = " + val);
					int temp = (int) val % (int)echelle;
					noiseMap[x, y] = val - temp;
					noiseMap[x, y] /= precision;
					//Debug.Log("noiseMap = " + noiseMap[x, y]);

				} else {
					//float normalizedHeight = (noiseMap [x, y] + 1) / (maxPossibleHeight/0.9f);
					//noiseMap [x, y] = Mathf.Clamp(normalizedHeight,0, int.MaxValue);
					noiseMap [x, y] = Mathf.InverseLerp (0, 1.0f, noiseMap [x, y]);
					//noiseMap[x, y] *= ratio;
					int val = (int) (noiseMap[x, y] * precision);
					//Debug.Log("val = " + val);
					int temp = (int) val % (int)echelle;
					noiseMap[x, y] = val - temp;
					noiseMap[x, y] /= precision;
					//Debug.Log("noiseMap = " + noiseMap[x, y]);
				}
			}
		}

		return noiseMap;
	}

}
