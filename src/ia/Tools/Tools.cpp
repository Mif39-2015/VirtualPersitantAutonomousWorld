#include "ia/Tools/Tools.hpp"
#include "ia/Entity/Item.hpp"
#include "ia/Entity/Characteristics.hpp"
#include "ia/Behavior/Comportement.hpp"

std::string readFileForName(std::string filename)
{
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

	//~ std::ifstream fichier(filename, std::ios::in);  // on ouvre le fichier en lecture
	//~
	//~ if(fichier){  // si l'ouverture a réussi
	//~ std::vector<std::string> vect;
	//~ std::string line;
	//~ while(std::getline(fichier, line)){
	//~ if (line != "")
	//~ vect.push_back(line);
	//~ }
	//~ fichier.close();  // on ferme le fichier
	//~
	//~ int i = rand<int>(0, vect.size());
	//~
	//~ return vect[i];
	//~ }

	else {
		return "noname";
	}
}

std::string getRandomMaleName()
{
	return readFileForName(PATH_DATA"/nameListMale.json");
}

std::string getRandomFemaleName()
{
	return readFileForName(PATH_DATA"/nameListFemale.json");
}

std::vector<std::string> cutString(std::string & str, std::string delimiter)
{
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

map<pair<int, int>, char> getResourcesMap(string nomFichier)
{
	ifstream fichier(PATH_DATA"/map.json", ios::in);  // on ouvre

	string fichierjsonstring = "";
	string ligne;

	map<pair<int, int>, char> carte;

	if (fichier) {
		while (getline(fichier, ligne)) { // tant que l'on peut mettre la ligne dans "contenu"
			fichierjsonstring += ligne;
		}

		fichier.close();
	}

	else {
		cerr << "Impossible d'ouvrir le fichier !" << endl;
		return carte;
	}

	char *fichierjson = (char *) malloc(fichierjsonstring.size());
	strcpy(fichierjson, fichierjsonstring.c_str());
	cJSON* root = cJSON_Parse(fichierjson);

	cJSON* mapSize = cJSON_GetObjectItem(root, "mapSize");
	char* size = cJSON_Print(mapSize);

	cJSON* mapGenerator = cJSON_GetObjectItem(root, "mapGeneratorData");
	cJSON* mapChunkSize = cJSON_GetObjectItem(mapGenerator, "mapChunkSize");
	char* sizeChunk = cJSON_Print(mapChunkSize);

	cJSON* chunks = cJSON_GetObjectItem(root, "chunks");
	cJSON *chunks_array = cJSON_GetArrayItem(chunks, 0);

	for (int i = 0 ; i < cJSON_GetArraySize(chunks_array) ; i++) {
		cJSON *chunk = cJSON_GetArrayItem(chunks_array, i);
		cJSON *resourceMap = cJSON_GetObjectItem(chunk, "resourceMap");

		for (int y = 0 ; y < cJSON_GetArraySize(resourceMap) ; y++) {
			cJSON *lignechunk = cJSON_GetArrayItem(resourceMap, y);

			for (int x = 0 ; x < cJSON_GetArraySize(lignechunk) ; x++) {
				cJSON *val = cJSON_GetArrayItem(lignechunk, x);
				char* value = cJSON_Print(val);
				carte[make_pair(x, y)] = value[0];
			}
		}
	}

	free(fichierjson);

	return carte;
}

map<pair<int, int>, float> getHauteursMap(string nomFichier)
{
	ifstream fichier(PATH_DATA"/map.json", ios::in);  // on ouvre

	string fichierjsonstring = "";
	string ligne;

	map<pair<int, int>, float> carteH;

	if (fichier) {
		while (getline(fichier, ligne)) { // tant que l'on peut mettre la ligne dans "contenu"
			fichierjsonstring += ligne;
		}

		fichier.close();
	} else {
		cerr << "Impossible d'ouvrir le fichier !" << endl;
		return carteH;
	}

	char *fichierjson = (char *) malloc(fichierjsonstring.size());
	strcpy(fichierjson, fichierjsonstring.c_str());
	cJSON* root = cJSON_Parse(fichierjson);

	cJSON* mapSize = cJSON_GetObjectItem(root, "mapSize");
	char* size = cJSON_Print(mapSize);

	cJSON* mapGenerator = cJSON_GetObjectItem(root, "mapGeneratorData");
	cJSON* mapChunkSize = cJSON_GetObjectItem(mapGenerator, "mapChunkSize");
	char* sizeChunk = cJSON_Print(mapChunkSize);

	cJSON* chunks = cJSON_GetObjectItem(root, "chunks");
	cJSON *chunks_array = cJSON_GetArrayItem(chunks, 0);

	for (int i = 0 ; i < cJSON_GetArraySize(chunks_array) ; i++) {
		cJSON *chunk = cJSON_GetArrayItem(chunks_array, i);

		cJSON *heightMap = cJSON_GetObjectItem(chunk, "heightMap");

		for (int y = 0 ; y < cJSON_GetArraySize(heightMap) ; y++) {
			cJSON *lignechunk = cJSON_GetArrayItem(heightMap, y);

			for (int x = 0 ; x < cJSON_GetArraySize(lignechunk) ; x++) {
				cJSON *val = cJSON_GetArrayItem(lignechunk, x);
				float value = atof(cJSON_Print(val));
				carteH[make_pair(x, y)] = value;
			}
		}
	}

	free(fichierjson);

	return carteH;
}

int getComportements(string nomFichier)
{
	ifstream fichier(nomFichier, ios::in);

	string fileString = "";
	string ligne;

	if (fichier) {
		while (getline(fichier, ligne)) {
			fileString += ligne;
		}

		fichier.close();
	} else {
		cerr << "Impossible d'ouvrir le fichier " << nomFichier << " ! " << endl;
		exit(0);
	}

	char * fileChar = (char *) malloc(sizeof(char) * fileString.size());
	strncpy(fileChar , fileString.c_str(), fileString.size());

        cJSON * root = cJSON_Parse(fileChar);

        cJSON * behaviors = cJSON_GetObjectItem(root, "behaviors");

        // cout << cJSON_Print(behaviors) << endl;

        cJSON * behavior;
        cJSON * nodes;
        cJSON * node;

        cJSON * aretes;
        cJSON * arete;

        map<int, Noeud> mapNoeuds;
        map<int, Arete> mapAretes;

        for (int b = 0; b < cJSON_GetArraySize(behaviors) ; ++b) {
            behavior = cJSON_GetArrayItem(behaviors, b);
            nodes = cJSON_GetObjectItem(behavior, "nodes");

            for (int n = 0 ; n < cJSON_GetArraySize(nodes) ; ++n) {
                node = cJSON_GetArrayItem(nodes, n);
                int id = cJSON_GetObjectItem(node, "id")->valueint;
                cout << " id : " << id << endl;
            }

            aretes = cJSON_GetObjectItem(behavior, "aretes");

            cout << endl << "ARETES : " << endl;

            for (int a = 0; a < cJSON_GetArraySize(aretes) ; ++a) {
                arete = cJSON_GetArrayItem(aretes, a);
                cout << cJSON_Print(arete) << endl;
            }
	}

	cout << "FIN ? " << endl;
	cout << "FIN2 ? " << endl;
	cout << "FIN3 ? " << endl;
	cout << "FIN4 ? " << endl;
	return 0;
}

bool loadAllFiles()
{
	int loadResult  = Characteristics::loadCharacteristicsFile(PATH_DATA"/descriptionCharacteristics.json");
	int loadResult2 = Comportement::initVectorComp(PATH_DATA"/foo.json");
	int loadResult3 = Item::loadItemsFile(PATH_DATA"/descriptionItems.json");
	int loadResult4 = 0; //TODO le chargement des comportements

	return loadResult != -1 && loadResult2 != -1 && loadResult3 != -1 && loadResult4 != -1;
}
