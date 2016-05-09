#include <iostream>
#include <string>
#include <sstream>
#include <string.h>

#include "serveur_catch.hpp"

#include "ia/Behavior/Action.hpp"
#include "ia/Behavior/Arete.hpp"
#include "ia/Behavior/Comportement.hpp"
#include "ia/Behavior/EtatEnum.hpp"
#include "ia/Behavior/FonctionEnums.hpp"
#include "ia/Behavior/Noeud.hpp"

#include "ia/Entity/Characteristics.hpp"
#include "ia/Entity/Entity.hpp"
#include "ia/Entity/Insentient_Entity.hpp"
#include "ia/Entity/Item.hpp"
#include "ia/Entity/Sentient_Entity.hpp"
#include "ia/Entity/Tangible_Entity.hpp"
#include "ia/Entity/Tribe.hpp"

#include "ia/Tools/Factories.hpp"
#include "ia/Tools/Position.hpp"
#include "ia/Tools/Astar.hpp"

#include "tool/cJSON.hpp"

using namespace std;

TEST_CASE("Test_File", "[file]")
{
    SECTION("Chargement FICHIER")
    {
        bool loadResult = loadAllFiles();
        REQUIRE(loadResult);

        std::cout << "I loaded the file !" << std::endl;

        for (auto it = begin (Characteristics::listCharacteristics); it != end (Characteristics::listCharacteristics); ++it) {
            std::cout << it->getType() << std::endl ;
        }

        Sentient_Entity * agent = Factories::createAgent();
        std::cout << agent->getName() << std::endl;

    }
    
    SECTION("Parsage JSON map")
    {
        std::cout << "Parsage JSON map" << std::endl;
		ifstream fichier(PATH_DATA"/map.json", ios::in);  // on ouvre
		
		string fichierjsonstring = "";
		string ligne;
		
		map<pair<int,int>, char> carte;
		map<pair<int,int>, float> carteH;
		
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
			return;
		}
		
		char *fichierjson = (char *) malloc(fichierjsonstring.size());
		strcpy(fichierjson, fichierjsonstring.c_str());
		std::cout << "Récupération du fichier et copie dans un char*" << std::endl;
		cout << fichierjson << endl;	
		
		
		std::cout << "Lecture avec cJSON" << std::endl;
		cJSON* root = cJSON_Parse(fichierjson);


		std::cout << "Récupération et affichage de la taille de la map en chunk" << std::endl;
		cJSON* mapSize = cJSON_GetObjectItem(root,"mapSize");
		char* size = cJSON_Print(mapSize);
		cout << size << endl;

		std::cout << "Récupération et affichage de la taille d'un chunk" << std::endl;
		cJSON* mapGenerator = cJSON_GetObjectItem(root,"mapGeneratorData");
		cJSON* mapChunkSize = cJSON_GetObjectItem(mapGenerator,"mapChunkSize");
		char* sizeChunk = cJSON_Print(mapChunkSize);
		cout << sizeChunk << endl;

		cJSON* chunks = cJSON_GetObjectItem(root,"chunks");
		cJSON *chunks_array = cJSON_GetArrayItem(chunks, 0);
		for (int i = 0 ; i < cJSON_GetArraySize(chunks_array) ; i++){	
			std::cout << "Récupération et affichage des valeurs des ressources dans les chunks" << std::endl;		
			cJSON *chunk = cJSON_GetArrayItem(chunks_array, i);
			cJSON *resourceMap = cJSON_GetObjectItem(chunk, "resourceMap");
			for (int x = 0 ; x < cJSON_GetArraySize(resourceMap) ; x++){			
				cJSON *lignechunk = cJSON_GetArrayItem(resourceMap, x);
				for (int y = 0 ; y < cJSON_GetArraySize(lignechunk) ; y++){
					cJSON *val = cJSON_GetArrayItem(lignechunk, y);
					char* value = cJSON_Print(val);
					carte[make_pair(x,y)] = value[0];
					cout << carte[make_pair(x,y)] << " ";			
				}
				cout << endl;
			}
		
			std::cout << "Récupération et affichage des valeurs des hauteurs dans les chunks" << std::endl;
			cJSON *heightMap = cJSON_GetObjectItem(chunk, "heightMap");
			for (int x = 0 ; x < cJSON_GetArraySize(heightMap) ; x++){			
				cJSON *lignechunk = cJSON_GetArrayItem(heightMap, x);
				for (int y = 0 ; y < cJSON_GetArraySize(lignechunk) ; y++){
					cJSON *val = cJSON_GetArrayItem(lignechunk, y);
					float value = atof(cJSON_Print(val));
					carteH[make_pair(x,y)] = value;
					cout << carteH[make_pair(x,y)] << " ";		
					
				}
				cout << endl;
			}
			
							
		}
		
		// FREE
		free(fichierjson);
	
    }
    
}
