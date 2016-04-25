using UnityEngine;
using System;
using System.Collections;
using System.Linq;
using System.Collections.Generic;
using System.IO;

public class GeneratePrefab : MonoBehaviour {

	//private GameObject scene;
	int width, height;
	Tilde[,] tilde;
	public string FileName;
	StreamReader sr; 
	char[] delimiterChar = { ' ' };
	List<Vector2> bugCase;
	bool firstGenerate;
	// Use this for initialization
	void Start () {
		//scene = new GameObject();
		sr = new StreamReader(FileName);
		string line = sr.ReadLine();
		string[] dC = line.Split (delimiterChar);
		//Debug.Log (tmp);
		width = Int32.Parse(dC[0]);
		height = Int32.Parse(dC[1]);
		//Debug.Log (width.ToString () + " " + height.ToString ());
		tilde = new Tilde[width, height];
		int x = 0, y = 0;
		while ((line = sr.ReadLine ()) != null) 
		{
			dC = line.Split (delimiterChar);
			Tilde tmpTilde = new Tilde();
			float h;
			tmpTilde.name = dC [3];
			if (dC [3] == "Water")
				h = 6;
			else
				h = float.Parse (dC [2]) * 20;
			tmpTilde.position = new Vector3 (float.Parse(dC [0])*2,h,float.Parse(dC [1])*2);
			tilde[x,y] =  tmpTilde;
			x++;
			if (x >= width) 
			{
				x = 0;
				y++;
			}
		}
		firstGenerate = false;
		bugCase = new List<Vector2> ();
		for (int i = 1; i < width - 1; i++)
			for (int j = 1; j < height - 1; j++) {
				GenerateName (new Vector2 (i, j));
			}
		firstGenerate = true;
		Debug.Log (bugCase.Count);


	}
	void GenerateName (Vector2 pos)
	{
		int check = 0;
		if (tilde [(int)pos.x, (int)pos.y].name == "Land")
			check = 0;
		if (tilde [(int)pos.x, (int)pos.y].name == "Mountain")
			check = 1;
		if (tilde [(int)pos.x, (int)pos.y].name == "Snow")
			check = 2;
		if (CheckCornerConcave (pos)) 
		{
			if(check == 0)
				tilde[(int)pos.x, (int)pos.y].name = "wall_01_corner_concave";
			if(check == 1)
				tilde[(int)pos.x, (int)pos.y].name = "wall_02_corner_concave";
			if(check == 2)
				tilde[(int)pos.x, (int)pos.y].name = "wall_03_corner_concave";
			return;
		} 
		if (CheckCornerConvex (pos)) 
		{
			if(check == 0)
				tilde[(int)pos.x, (int)pos.y].name = "wall_01_corner_convex";
			if(check == 1)
				tilde[(int)pos.x, (int)pos.y].name = "wall_02_corner_convex";
			if(check == 2)
				tilde[(int)pos.x, (int)pos.y].name = "wall_03_corner_convex";
			return;
		} 
		if (CheckTile(pos)) 
		{
			if(check == 0)
				tilde[(int)pos.x, (int)pos.y].name = "wall_01_tile_01";
			if(check == 1)
				tilde[(int)pos.x, (int)pos.y].name = "wall_02_tile_01";
			if(check == 2)
				tilde[(int)pos.x, (int)pos.y].name = "wall_03_tile";
			return;
		} 
		if (CheckTile2 (pos) && !firstGenerate) 
		{
			tilde [(int)pos.x, (int)pos.y].position.y -= 2;
			return;
		}
		tilde [(int)pos.x, (int)pos.y].rotation = Vector3.zero;
		return;
	}
	bool HeightCmp(Vector2 pos1, Vector2  pos2)
	{
		if (tilde [(int)pos1.x, (int)pos1.y].position.y >= tilde [(int)pos2.x, (int)pos2.y].position.y)
			return true;
		else
			return false;
	}
	bool CheckCornerConcave(Vector2 pos)
	{
		Vector2 pos11 = new Vector2 (pos.x + 1, pos.y + 1);
		Vector2 pos01 = new Vector2 (pos.x, pos.y + 1);
		Vector2 pos_11 = new Vector2 (pos.x - 1, pos.y + 1);
		Vector2 pos10 = new Vector2 (pos.x + 1, pos.y);
		Vector2 pos_10 = new Vector2 (pos.x - 1, pos.y);
		Vector2 pos1_1 = new Vector2 (pos.x + 1, pos.y - 1);
		Vector2 pos0_1 = new Vector2 (pos.x, pos.y - 1);
		Vector2 pos_1_1 = new Vector2 (pos.x - 1, pos.y - 1);
		if (HeightCmp (pos11, pos) && HeightCmp (pos01, pos) && HeightCmp (pos_11, pos) &&
		    HeightCmp (pos10, pos) &&							HeightCmp (pos_10, pos) &&
		   !HeightCmp (pos1_1, pos) && HeightCmp (pos0_1, pos) && HeightCmp (pos_1_1, pos)) 
		{
			tilde [(int)pos.x,(int) pos.y].rotation = new Vector3 (0f, 90f, 0f);
			return true;
		}
		if (!HeightCmp (pos11, pos) && HeightCmp (pos01, pos) && HeightCmp (pos_11, pos) &&
			HeightCmp (pos10, pos) && HeightCmp (pos_10, pos) &&
			HeightCmp (pos1_1, pos) && HeightCmp (pos0_1, pos) && HeightCmp (pos_1_1, pos)) 
		{
			tilde [(int)pos.x, (int)pos.y].rotation = new Vector3 (0f, 0f, 0f);
			return true;
		}
		if (HeightCmp (pos11, pos) && HeightCmp (pos01, pos) && !HeightCmp (pos_11, pos) &&
			HeightCmp (pos10, pos) && HeightCmp (pos_10, pos) &&
			HeightCmp (pos1_1, pos) && HeightCmp (pos0_1, pos) && HeightCmp (pos_1_1, pos)) 
		{
			tilde [(int)pos.x, (int)pos.y].rotation = new Vector3 (0f, -90f, 0f);
			return true;
		}
		if (HeightCmp (pos11, pos) && HeightCmp (pos01, pos) && HeightCmp (pos_11, pos) &&
			HeightCmp (pos10, pos) && HeightCmp (pos_10, pos) &&
			HeightCmp (pos1_1, pos) && HeightCmp (pos0_1, pos) && !HeightCmp (pos_1_1, pos)) 
		{
			tilde [(int)pos.x, (int)pos.y].rotation = new Vector3 (0f, 180f, 0f);
			return true;
		}
		return false;
	}
	bool CheckCornerConvex(Vector2 pos)
	{
		Vector2 pos11 = new Vector2 (pos.x + 1, pos.y + 1);
		Vector2 pos01 = new Vector2 (pos.x, pos.y + 1);
		Vector2 pos_11 = new Vector2 (pos.x - 1, pos.y + 1);
		Vector2 pos10 = new Vector2 (pos.x + 1, pos.y);
		Vector2 pos_10 = new Vector2 (pos.x - 1, pos.y);
		Vector2 pos1_1 = new Vector2 (pos.x + 1, pos.y - 1);
		Vector2 pos0_1 = new Vector2 (pos.x, pos.y - 1);
		Vector2 pos_1_1 = new Vector2 (pos.x - 1, pos.y - 1);
		if (HeightCmp (pos11, pos) && HeightCmp (pos01, pos) &&
			HeightCmp (pos10, pos) && !HeightCmp (pos_10, pos) &&
			!HeightCmp (pos0_1, pos) )//&& !HeightCmp (pos_1_1, pos)) 
		{
			tilde [(int)pos.x,(int) pos.y].rotation = new Vector3 (0f, 180f, 0f);
			return true;
		}
		if (HeightCmp (pos01, pos) && HeightCmp (pos_11, pos) &&
			!HeightCmp (pos10, pos) && 	HeightCmp (pos_10, pos) &&
			//!HeightCmp (pos1_1, pos) && 
			!HeightCmp (pos0_1, pos)) 
		{
			tilde [(int)pos.x, (int)pos.y].rotation = new Vector3 (0f, 90f, 0f);
			return true;
		}
		if (//!HeightCmp (pos11, pos) && 
			!HeightCmp (pos01, pos)&&
			!HeightCmp (pos10, pos) && 	HeightCmp (pos_10, pos) &&
			HeightCmp (pos0_1, pos) && HeightCmp (pos_1_1, pos)) 
		{
			tilde [(int)pos.x, (int)pos.y].rotation = new Vector3 (0f, 0f, 0f);
			return true;
		}
		if (!HeightCmp (pos01, pos) && 
			//!HeightCmp (pos_11, pos) &&
			HeightCmp (pos10, pos) && !HeightCmp (pos_10, pos) &&
			HeightCmp (pos1_1, pos) && HeightCmp (pos0_1, pos)) 
		{
			tilde [(int)pos.x, (int)pos.y].rotation = new Vector3 (0f, -90f, 0f);
			return true;
		}
		return false;
	}
	bool CheckTile(Vector2 pos)
	{
		Vector2 pos11 = new Vector2 (pos.x + 1, pos.y + 1);
		Vector2 pos01 = new Vector2 (pos.x, pos.y + 1);
		Vector2 pos_11 = new Vector2 (pos.x - 1, pos.y + 1);
		Vector2 pos10 = new Vector2 (pos.x + 1, pos.y);
		Vector2 pos_10 = new Vector2 (pos.x - 1, pos.y);
		Vector2 pos1_1 = new Vector2 (pos.x + 1, pos.y - 1);
		Vector2 pos0_1 = new Vector2 (pos.x, pos.y - 1);
		Vector2 pos_1_1 = new Vector2 (pos.x - 1, pos.y - 1);
		if (HeightCmp (pos11, pos) && HeightCmp (pos01, pos) && HeightCmp (pos_11, pos) &&
			HeightCmp (pos10, pos) &&							HeightCmp (pos_10, pos) &&
			!HeightCmp (pos0_1, pos)) 
		{
			tilde [(int)pos.x,(int) pos.y].rotation = new Vector3 (0f, 180f, 0f);
			return true;
		}
		if ( HeightCmp (pos01, pos) && HeightCmp (pos_11, pos) &&
			!HeightCmp (pos10, pos) && HeightCmp (pos_10, pos) &&
			HeightCmp (pos0_1, pos) && HeightCmp (pos_1_1, pos)) 
		{
			tilde [(int)pos.x, (int)pos.y].rotation = new Vector3 (0f, 90f, 0f);
			return true;
		}
		if (!HeightCmp (pos01, pos) &&
			HeightCmp (pos10, pos) && HeightCmp (pos_10, pos) &&
			HeightCmp (pos1_1, pos) && HeightCmp (pos0_1, pos) && HeightCmp (pos_1_1, pos)) 
		{
			tilde [(int)pos.x, (int)pos.y].rotation = Vector3.zero;
			return true;
		}
		if (HeightCmp (pos11, pos) && HeightCmp (pos01, pos) &&
			HeightCmp (pos10, pos) && !HeightCmp (pos_10, pos) &&
			HeightCmp (pos1_1, pos) && HeightCmp (pos0_1, pos)) 
		{
			tilde [(int)pos.x, (int)pos.y].rotation = new Vector3 (0f, -90f, 0f);
			return true;
		}
		return false;
	}
	bool CheckTile2(Vector2 pos)
	{
		Vector2 pos11 = new Vector2 (pos.x + 1, pos.y + 1);
		Vector2 pos01 = new Vector2 (pos.x, pos.y + 1);
		Vector2 pos_11 = new Vector2 (pos.x - 1, pos.y + 1);
		Vector2 pos10 = new Vector2 (pos.x + 1, pos.y);
		Vector2 pos_10 = new Vector2 (pos.x - 1, pos.y);
		Vector2 pos1_1 = new Vector2 (pos.x + 1, pos.y - 1);
		Vector2 pos0_1 = new Vector2 (pos.x, pos.y - 1);
		Vector2 pos_1_1 = new Vector2 (pos.x - 1, pos.y - 1);

		Vector2 lowTildePos = pos;
		int count = 8;
		if (HeightCmp (pos11, pos))
			count--;
		else
			lowTildePos = pos11;
		if (HeightCmp (pos01, pos))
			count--;
		else
			lowTildePos = pos01;
		if (HeightCmp (pos_11, pos))
			count--;
		else
			lowTildePos = pos_11;
		if (HeightCmp (pos10, pos))
			count--;
		else
			lowTildePos = pos10;
		if (HeightCmp (pos_10, pos))
			count--;
		else
			lowTildePos = pos_10;
		if (HeightCmp (pos1_1, pos))
			count--;
		else
			lowTildePos = pos1_1;
		if (HeightCmp (pos0_1, pos))
			count--;
		else
			lowTildePos = pos0_1;
		if (HeightCmp (pos_1_1, pos))
			count--;
		else
			lowTildePos = pos_1_1;
		if (count >= 5) 
		{
			tilde [(int)pos.x, (int)pos.y].rotation = new Vector3 (0f, 0f, 0f);
			tilde [(int)pos.x, (int)pos.y].name = tilde [(int)lowTildePos.x, (int)lowTildePos.y].name;
			return true;
		}
		if(count >2)
			bugCase.Add (pos);
		return false;
	}
	void CreatePrefab()
	{
		for(int i = 1; i < width-1; i++)
			for(int j = 1; j < height-1; j++)
			{
				GameObject tmp = (GameObject)Instantiate (Resources.Load (tilde[i,j].name));
				tmp.transform.Rotate (tilde [i, j].rotation);
				tmp.transform.position = tilde[i,j].position;
				tmp.transform.parent = transform;
				tilde [i, j].instance = tmp;
			}

	}

	// Update is called once per frame
	void Update () {
		if (Input.GetKeyDown (KeyCode.B)) 
		{
			List<Vector2> tmpBugCase = bugCase;
			Debug.Log (tmpBugCase.Count);
			//while(bugCase.Count != 0)
			for (int i = 0; i < tmpBugCase.Count; i++) 
			{
				GenerateName (bugCase [0]);
				bugCase.RemoveAt (0);
			}
			Debug.Log (bugCase.Count);
		}
		if (Input.GetKeyDown (KeyCode.Space)) 
		{
			CreatePrefab ();
		}
	}
}
public struct Tilde
{
	public GameObject instance;
	public string name;
	public Vector3 position;
	public Vector3 rotation;
}
