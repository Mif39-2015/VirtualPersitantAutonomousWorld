#include "ia/Tools/Tools.hpp"
#include "ia/Entity/Item.hpp"
#include "ia/Entity/Characteristics.hpp"
#include "ia/Behavior/Comportement.hpp"

std::string readFileForName(std::string filename) {
    ifstream file (filename, ios::in);
    if (file.is_open()) {
        string str((std::istreambuf_iterator<char>(file)), istreambuf_iterator<char>());

        std::vector<std::string> vect;
        file.close();

        cJSON *root = cJSON_Parse(str.c_str());

        cJSON *child = cJSON_GetObjectItem(root, "nameList");
        int nb = cJSON_GetArraySize(child);
        for (int i = 0; i < nb; i++) {
            cJSON *item = cJSON_GetArrayItem(child, i);

            cJSON *name = cJSON_GetObjectItem(item, "name");
            if (name->type == cJSON_String) {
                vect.push_back(name->valuestring);
            }
        }
        int i = rand<int>(0, vect.size());

        return vect[i];
    }

    // std::ifstream fichier(filename, std::ios::in);  // on ouvre le fichier en lecture
//
    // if(fichier){  // si l'ouverture a réussi
    // std::vector<std::string> vect;
    // std::string line;
    // while(std::getline(fichier, line)){
    // if (line != "")
    // vect.push_back(line);
    // }
    // fichier.close();  // on ferme le fichier
//
    // int i = rand<int>(0, vect.size());
//
    // return vect[i];
    // }

    else {
        return "noname";
    }
}

std::string getRandomMaleName() {
    return readFileForName(PATH_DATA"/nameListMale.json");
}

std::string getRandomFemaleName() {
    return readFileForName(PATH_DATA"/nameListFemale.json");
}

std::vector<std::string> cutString(std::string & str, std::string delimiter) {
    size_t pos = 0;
    std::vector<std::string> res;
    std::string token;
    while ((pos = str.find(delimiter)) != std::string::npos) {
        token = str.substr(0, pos);
        res.push_back(token);
        str.erase(0, pos + delimiter.length());
    }
    res.push_back(str);

    return res;
}

map<pair<int, int>, char> getResourcesMap(string nomFichier) {
	ifstream fichier(PATH_DATA + nomFichier, ios::in);  // on ouvre
	
	string fichierjsonstring = "";
	string ligne;
	
	map<pair<int,int>, char> carte;
	
	if(fichier)
	{
		while(getline(fichier, ligne))  // tant que l'on peut mettre la ligne dans "contenu"
		{
		 fichierjsonstring += ligne;
		}
		fichier.close();
	}
	else{
		cerr << "Impossible d'ouvrir le fichier !" << endl;
		return carte;
	}
	
	char *fichierjson = (char *) malloc(fichierjsonstring.size());
	strcpy(fichierjson, fichierjsonstring.c_str());
	cJSON* root = cJSON_Parse(fichierjson);

	cJSON* mapSize = cJSON_GetObjectItem(root,"mapSize");
	char* size = cJSON_Print(mapSize);

	cJSON* mapGenerator = cJSON_GetObjectItem(root,"mapGeneratorData");
	cJSON* mapChunkSize = cJSON_GetObjectItem(mapGenerator,"mapChunkSize");
	char* sizeChunk = cJSON_Print(mapChunkSize);

	cJSON* chunks = cJSON_GetObjectItem(root,"chunks");
	cJSON *chunks_array = cJSON_GetArrayItem(chunks, 0);
	
	int saveX = 0;
	int saveY = 0;
	
	for (int i = 0 ; i < cJSON_GetArraySize(chunks) ; i++){	
		saveY = 0;
		cJSON *chunks_array = cJSON_GetArrayItem(chunks, i);
		for (int j = 0 ; j < cJSON_GetArraySize(chunks_array) ; j++){	
			
			cJSON *chunk = cJSON_GetArrayItem(chunks_array, j);
			cJSON* positionMap = cJSON_GetObjectItem(chunk, "position");
			cJSON* positionX = cJSON_GetObjectItem(positionMap,"x");
			cJSON* positionY = cJSON_GetObjectItem(positionMap,"y");				
			cJSON *resourceMap = cJSON_GetObjectItem(chunk, "resourceMap");
			for (int y = 0 ; y < cJSON_GetArraySize(resourceMap) ; y++){			
				cJSON *lignechunk = cJSON_GetArrayItem(resourceMap, y);
				for (int x = 0 ; x < cJSON_GetArraySize(lignechunk) ; x++){
					cJSON *val = cJSON_GetArrayItem(lignechunk, x);
					char* value = cJSON_Print(val);
					carte[make_pair(x+saveX,y+saveY)] = value[0];	
				} 
			}
			saveY += atoi(sizeChunk);			
		}
		saveX += atoi(sizeChunk);		
	}
	
	free(fichierjson);

    return carte;
}

map<pair<int, int>, float> getHauteursMap(string nomFichier) {
	ifstream fichier(PATH_DATA + nomFichier, ios::in);  // on ouvre
	
	string fichierjsonstring = "";
	string ligne;
	
	map<pair<int,int>, float> carte;
	
	if(fichier)
	{
		while(getline(fichier, ligne))  // tant que l'on peut mettre la ligne dans "contenu"
		{
		 fichierjsonstring += ligne;
		}
		fichier.close();
	}
	else{
		cerr << "Impossible d'ouvrir le fichier !" << endl;
		return carte;
	}
	
	char *fichierjson = (char *) malloc(fichierjsonstring.size());
	strcpy(fichierjson, fichierjsonstring.c_str());
	cJSON* root = cJSON_Parse(fichierjson);

	cJSON* mapSize = cJSON_GetObjectItem(root,"mapSize");
	char* size = cJSON_Print(mapSize);

	cJSON* mapGenerator = cJSON_GetObjectItem(root,"mapGeneratorData");
	cJSON* mapChunkSize = cJSON_GetObjectItem(mapGenerator,"mapChunkSize");
	char* sizeChunk = cJSON_Print(mapChunkSize);

	cJSON* chunks = cJSON_GetObjectItem(root,"chunks");
	cJSON *chunks_array = cJSON_GetArrayItem(chunks, 0);
	
	int saveX = 0;
	int saveY = 0;
	
	for (int i = 0 ; i < cJSON_GetArraySize(chunks) ; i++){	
		saveY = 0;
		cJSON *chunks_array = cJSON_GetArrayItem(chunks, i);
		for (int j = 0 ; j < cJSON_GetArraySize(chunks_array) ; j++){	
			
			cJSON *chunk = cJSON_GetArrayItem(chunks_array, j);
			cJSON* positionMap = cJSON_GetObjectItem(chunk, "position");
			cJSON* positionX = cJSON_GetObjectItem(positionMap,"x");
			cJSON* positionY = cJSON_GetObjectItem(positionMap,"y");					
			cJSON *heightMap = cJSON_GetObjectItem(chunk, "heightMap");
			for (int y = 0 ; y < cJSON_GetArraySize(heightMap) ; y++){			
				cJSON *lignechunk = cJSON_GetArrayItem(heightMap, y);
				for (int x = 0 ; x < cJSON_GetArraySize(lignechunk) ; x++){
					cJSON *val = cJSON_GetArrayItem(lignechunk, x);
					float value = atof(cJSON_Print(val));
					carte[make_pair(x+saveX,y+saveY)] = value;				
				}
			}
			saveY += atoi(sizeChunk);	
					
		}
		saveX += atoi(sizeChunk);		
	}
	
	free(fichierjson);

    return carte;
}

bool loadAllFiles() {
    int loadResult  = Characteristics::loadCharacteristicsFile(PATH_DATA"/descriptionCharacteristics.json");
    int loadResult2 = Comportement::initVectorComp(PATH_DATA"/foo.json");
    int loadResult3 = Item::loadItemsFile(PATH_DATA"/descriptionItems.json");

    return loadResult != -1 && loadResult2 != -1 && loadResult3 != -1;
}
