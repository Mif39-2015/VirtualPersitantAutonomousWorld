#include "ia/Tools/Tools.hpp"
#include "ia/Entity/Item.hpp"
#include "ia/Entity/Characteristics.hpp"
#include "ia/Behavior/Comportement.hpp"
#include "ia/Behavior/FonctionEnums.hpp"

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

map<pair<int, int>, char> getResourcesMap(string nomFichier) {
	ifstream fichier(PATH_DATA + nomFichier, ios::in);  // on ouvre
	
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
	} else {
		cerr << "Impossible d'ouvrir le fichier !" << endl;
		return carte;
	}

	char *fichierjson = (char *) malloc(fichierjsonstring.size() + 1);
	strcpy(fichierjson, fichierjsonstring.c_str());
	cJSON* root = cJSON_Parse(fichierjson);

	cJSON* mapSize = cJSON_GetObjectItem(root, "mapSize");
	char* size = cJSON_Print(mapSize);

	cJSON* mapGenerator = cJSON_GetObjectItem(root, "mapGeneratorData");
	cJSON* mapChunkSize = cJSON_GetObjectItem(mapGenerator, "mapChunkSize");
	char* sizeChunk = cJSON_Print(mapChunkSize);

	cJSON* chunks = cJSON_GetObjectItem(root, "chunks");
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

vector<Comportement *> getComportements(string nomFichier)
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

	char * fileChar = (char *) malloc(sizeof(char) * (fileString.size() + 1));
	strcpy(fileChar , fileString.c_str());

	cJSON * root = cJSON_Parse(fileChar);

	cJSON * behaviors = cJSON_GetObjectItem(root, "behaviors");

	map<int, Noeud *> mapNoeuds;
	map<int, Comportement *> mapComportement;

	vector<Comportement *> retour;

	for (int b = 0; b < cJSON_GetArraySize(behaviors) ; ++b) {
		cJSON *	behaviorCJSON = cJSON_GetArrayItem(behaviors, b);
		cJSON * nodes = cJSON_GetObjectItem(behaviorCJSON, "nodes");

		int idBehavior = cJSON_GetObjectItem(behaviorCJSON, "id")->valueint;

		cJSON * idDepartCJSON = cJSON_GetObjectItem(behaviorCJSON, "id_depart");
		int idDepart;

		if (idDepartCJSON->type == cJSON_Number)
			idDepart = idDepartCJSON->valueint;
		else
			idDepart =  -1;

		cJSON * idFinCJSON = cJSON_GetObjectItem(behaviorCJSON, "id_fin");

		vector<int> idFin;

		for (int iidFin = 0 ; iidFin < cJSON_GetArraySize(idFinCJSON) ; ++iidFin) {
			idFin.push_back(cJSON_GetArrayItem(idFinCJSON, iidFin)->valueint);
		}

		Comportement * behavior = new Comportement();

		for (int n = 0 ; n < cJSON_GetArraySize(nodes) ; ++n) {
			cJSON * node = cJSON_GetArrayItem(nodes, n);

			int idNode = cJSON_GetObjectItem(node, "id")->valueint;

			cJSON * action = cJSON_GetObjectItem(node, "action");

			cJSON * comportement = cJSON_GetObjectItem(action, "comportement");

			Noeud * noeud = new Noeud();
			mapNoeuds[idNode] = noeud;

			if (comportement->type == cJSON_String) {
				string fvString(cJSON_GetObjectItem(action, "fv")->valuestring);

				if (fvString != "null") {
					FONC_VOID fvAction = MapEnumString::mapFoncVoid[fvString];
					ActionSimple * as = new ActionSimple(fvAction);
					noeud->setAction(as);
				} else {
					string fveString(cJSON_GetObjectItem(action, "fve")->valuestring);

					if (fveString != "null") {

						if (MapEnumString::mapFoncVoidEntity.find(fveString.c_str()) != MapEnumString::mapFoncVoidEntity.end()) {

							FONC_VOID_ENTITY fve = MapEnumString::mapFoncVoidEntity[fveString.c_str()];

							cJSON * sfeeCJSON = cJSON_GetObjectItem(action, "sfee");
							stack<FONC_ENTITY_ENTITY> sfee;

							for (int isfee = 0; isfee < cJSON_GetArraySize(sfeeCJSON) ; ++isfee) {
								string feeString(cJSON_GetArrayItem(sfeeCJSON, isfee)->valuestring);

								if (feeString != "null") {
									if (MapEnumString::mapFoncEntityEntity.find(feeString) != MapEnumString::mapFoncEntityEntity.end()) {
										sfee.push(MapEnumString::mapFoncEntityEntity[feeString]);
									} else {
										cout << "Erreur dans sfee : " << feeString << " n'est pas une fonction de FONC_ENTITY_ENTITY" << endl;
									}
								}
							}

							string paramFinalString(cJSON_GetObjectItem(action, "paramFinal")->valuestring);

							if (paramFinalString != "null") {
								if (MapEnumString::mapFoncEntity.find(paramFinalString.c_str()) != MapEnumString::mapFoncEntity.end()) {

									FONC_ENTITY paramFinal = MapEnumString::mapFoncEntity[paramFinalString.c_str()];

									ActionSimple * as = new ActionSimple(fve, sfee, paramFinal);
									noeud->setAction(as);
								}
							}
						} else {
							cout << "Erreur dans fve : " << fveString << " n'est pas une fonction de FONC_VOID_ENTITY" << endl;
						}
					}
				}
			} else {
				mapComportement[comportement->valueint] = new Comportement();
				ActionComportement * ac = new ActionComportement(mapComportement[comportement->valueint]);
				noeud->setAction(ac);
			}

			behavior->ajouterNoeud(noeud);

			if (idDepart == idNode) {
				behavior->setNoeudDepart(noeud);
			}

			if (findInVector(idFin , idNode) != -1) {
				behavior->ajouterNoeudFin(noeud);
			}
		}

		cJSON * aretes = cJSON_GetObjectItem(behaviorCJSON, "aretes");

		for (int a = 0; a < cJSON_GetArraySize(aretes) ; ++a) {
			cJSON * areteCJSON = cJSON_GetArrayItem(aretes, a);
			// cout << cJSON_Print(arete) << endl;
			int idDepart = cJSON_GetObjectItem(areteCJSON, "id_depart")->valueint;
			int idFin = cJSON_GetObjectItem(areteCJSON, "id_fin")->valueint;

			Noeud * nDepart = mapNoeuds[idDepart];
			Noeud * nFin = mapNoeuds[idFin];

			Arete * arete = new Arete(nDepart, nFin);

			vector<FONC_BOOL> condition_simples;

			cJSON * conditionSimpleArrayCJSON = cJSON_GetObjectItem(areteCJSON, "condition_simple");

			for (int cs = 0 ; cs < cJSON_GetArraySize(conditionSimpleArrayCJSON) ; ++cs) {
				cJSON * conditionSimpleCJSON = cJSON_GetArrayItem(conditionSimpleArrayCJSON, cs);
				string cond(conditionSimpleCJSON->valuestring);

				if (cond != "null") {
					if (MapEnumString::mapFoncBool.find(cond) != MapEnumString::mapFoncBool.end()) {
						condition_simples.push_back(MapEnumString::mapFoncBool[cond]);
					} else {
						cout << "Erreur dans condition_simple : " << cond << " n'est pas une FONC_BOOL" << endl;
					}
				}
			}

			arete->setCondition_Simple(condition_simples);

			vector<struct_condition> condition_complexes;
			cJSON * conditionComplexeArrayCJSON = cJSON_GetObjectItem(areteCJSON, "condition_complexe");

			for (int cc = 0 ; cc < cJSON_GetArraySize(conditionComplexeArrayCJSON) ; ++cc) {
				cJSON * conditionComplexeCJSON = cJSON_GetArrayItem(conditionComplexeArrayCJSON , cc);

				string fie1(cJSON_GetObjectItem(conditionComplexeCJSON, "fie1")->valuestring);
				string fie2(cJSON_GetObjectItem(conditionComplexeCJSON, "fie2")->valuestring);
				string operatorString(cJSON_GetObjectItem(conditionComplexeCJSON, "operator")->valuestring);

				cJSON * compareCJSON = cJSON_GetObjectItem(conditionComplexeCJSON, "comp");

				struct_condition struct_cond;

				stack<FONC_ENTITY_ENTITY> sfee1;

				if (fie1 != "null") {
					if (MapEnumString::mapFoncIntEntity.find(fie1) != MapEnumString::mapFoncIntEntity.end()) {
						struct_cond.fIE1 = MapEnumString::mapFoncIntEntity[fie1];

						cJSON * sfee1CJSON = cJSON_GetObjectItem(conditionComplexeCJSON, "sfee1");

						for (int isfee1 = 0 ; isfee1 < cJSON_GetArraySize(sfee1CJSON) ; ++isfee1) {
							string fee1(cJSON_GetArrayItem(sfee1CJSON, isfee1)->valuestring);

							if (fee1 != "null") {
								if (MapEnumString::mapFoncEntityEntity.find(fee1) != MapEnumString::mapFoncEntityEntity.end()) {
									sfee1.push(MapEnumString::mapFoncEntityEntity[fee1]);
								} else {
									cout << "Erreur dans condition_complexe::sfee1 : " << fee1 << " n'est pas une FONC_INT_ENTITY" << endl;
								}
							}
						}

						struct_cond.fEE1 = sfee1;

						bool deuxiemeConditionValide = false;

						if (fie2 != "null") {
							if (MapEnumString::mapFoncIntEntity.find(fie2) != MapEnumString::mapFoncIntEntity.end()) {
								struct_cond.fIE2 = MapEnumString::mapFoncIntEntity[fie2];

								cJSON * sfee2CJSON = cJSON_GetObjectItem(conditionComplexeCJSON, "sfee2");

								stack<FONC_ENTITY_ENTITY> sfee2;

								for (int isfee2 = 0 ; isfee2 < cJSON_GetArraySize(sfee2CJSON) ; ++isfee2) {
									string fee2(cJSON_GetArrayItem(sfee2CJSON, isfee2)->valuestring);

									if (fee2 != "null") {
										if (MapEnumString::mapFoncEntityEntity.find(fee2) != MapEnumString::mapFoncEntityEntity.end()) {
											sfee2.push(MapEnumString::mapFoncEntityEntity[fee2]);
										} else {
											cout << "Erreur dans condition_complexe::sfee2 : " << fee2 << " n'est pas une FONC_INT_ENTITY" << endl;
										}
									}
								}

								struct_cond.fEE2 = sfee2;

								deuxiemeConditionValide = true;
							} else {
								cout << "Erreur dans condition_complexe::fie2 : " << fie2 << " n'est pas une FONC_INT_ENTITY" << endl;
							}
						} else {
							if (compareCJSON->type == cJSON_Number) {
								struct_cond.comp = compareCJSON->valueint;
								deuxiemeConditionValide = true;
							}
						}

						if (deuxiemeConditionValide) {
							if (operatorString == "Inf")
								struct_cond.op = Inf;
							else if (operatorString == "Inf_eg")
								struct_cond.op = Inf_Eg;
							else if (operatorString == "Eg")
								struct_cond.op = Inf_Eg;
							else if (operatorString == "Sup_eg")
								struct_cond.op = Inf_Eg;
							else if (operatorString == "Sup")
								struct_cond.op = Inf_Eg;

							if (operatorString != "null") {
								condition_complexes.push_back(struct_cond);
							}
						}
					} else {
						cout << "Erreur dans condition_complexe::fie1 : " << fie1 << " n'est pas une FONC_INT_ENTITY" << endl;
					}
				}
			}

			arete->setCondition_Complexe(condition_complexes);
		}

		Comportement::addToComportements(behavior);

		mapComportement[idBehavior] = behavior;

		retour.push_back(behavior);

	}

	cJSON_Delete(root);

	free(fileChar);

	return retour;
}

bool loadAllFiles()
{
	int loadResult  = Characteristics::loadCharacteristicsFile(PATH_DATA"/descriptionCharacteristics.json");
	int loadResult2 = Comportement::initVectorComp(PATH_DATA"/foo.json");
	int loadResult3 = Item::loadItemsFile(PATH_DATA"/descriptionItems.json");
	int loadResult4 = 0; //TODO le chargement des comportements

	return loadResult != -1 && loadResult2 != -1 && loadResult3 != -1 && loadResult4 != -1;
}
