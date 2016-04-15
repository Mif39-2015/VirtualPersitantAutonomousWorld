#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <streambuf>

#include "serveur_catch.hpp"

#include "Behavior/Action.hpp"
#include "Behavior/ActionComportement.hpp"
#include "Behavior/ActionSimple.hpp"
#include "Behavior/Arete.hpp"
#include "Behavior/Comportement.hpp"
#include "Behavior/EtatEnum.hpp"
#include "Behavior/FonctionEnums.hpp"
#include "Behavior/Noeud.hpp"

#include "Entity/Characteristics.hpp"
#include "Entity/Entity.hpp"
#include "Entity/Insentient_Entity.hpp"
#include "Entity/Item.hpp"
#include "Entity/Sentient_Entity.hpp"
#include "Entity/Tangible_Entity.hpp"
#include "Entity/Tribe.hpp"

#include "Tools/Factories.hpp"
#include "tool/cJSON.hpp"

using namespace std;


TEST_CASE("Test import data files", "[data]")
{
	SECTION("Test import Characteristics_Agent.json")
	{
		ifstream file (PATH_DATA"/Characteristics_Agent.json", ios::in);
		if (file.is_open()){
			string str((std::istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
			
			file.close();

			cJSON *root = cJSON_Parse(str.c_str());
			
			cJSON *child = cJSON_GetObjectItem(root, "characteristicsAgent");
			int	nb = cJSON_GetArraySize(child);
			for(int i = 0; i < nb; i++){
				cJSON *item = cJSON_GetArrayItem(child, i);
				cJSON *id = cJSON_GetObjectItem(item,"id");
				if(id->type == cJSON_Number){
					cout << "carac: " << id->valueint << endl;
				}
			}
			
		} else {
		}
	}
	
	SECTION("Test import Characteristics_Animal.json")
	{
		ifstream file (PATH_DATA"/Characteristics_Animal.json", ios::in);
		if (file.is_open()){
			string str((std::istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
			
			file.close();

			cJSON *root = cJSON_Parse(str.c_str());
			
			cJSON *child = cJSON_GetObjectItem(root, "characteristicsAnimal");
			int	nb = cJSON_GetArraySize(child);
			for(int i = 0; i < nb; i++){
				cJSON *item = cJSON_GetArrayItem(child, i);
				cJSON *id = cJSON_GetObjectItem(item,"id");
				if(id->type == cJSON_Number){
					cout << "carac: " << id->valueint << endl;
				}
			}
			
		} else {
		}
	}
	
	SECTION("Test import Characteristics_Building.json")
	{
		ifstream file (PATH_DATA"/Characteristics_Building.json", ios::in);
		if (file.is_open()){
			string str((std::istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
			
			file.close();

			cJSON *root = cJSON_Parse(str.c_str());
			
			cJSON *child = cJSON_GetObjectItem(root, "characteristicsBuilding");
			int	nb = cJSON_GetArraySize(child);
			for(int i = 0; i < nb; i++){
				cJSON *item = cJSON_GetArrayItem(child, i);
				cJSON *id = cJSON_GetObjectItem(item,"id");
				if(id->type == cJSON_Number){
					cout << "carac: " << id->valueint << endl;
				}
			}
			
		} else {
		}
	}
	
	SECTION("Test import Characteristics_Item.json")
	{
		ifstream file (PATH_DATA"/Characteristics_Item.json", ios::in);
		if (file.is_open()){
			string str((std::istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
			
			file.close();

			cJSON *root = cJSON_Parse(str.c_str());
			
			cJSON *child = cJSON_GetObjectItem(root, "characteristicsItem");
			int	nb = cJSON_GetArraySize(child);
			for(int i = 0; i < nb; i++){
				cJSON *item = cJSON_GetArrayItem(child, i);
				cJSON *id = cJSON_GetObjectItem(item,"id");
				if(id->type == cJSON_Number){
					cout << "carac: " << id->valueint << endl;
				}
			}
			
		} else {
		}
	}
	
	SECTION("Test import Characteristics_Resource.json")
	{
		ifstream file (PATH_DATA"/Characteristics_Resource.json", ios::in);
		if (file.is_open()){
			string str((std::istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
			
			file.close();

			cJSON *root = cJSON_Parse(str.c_str());
			
			cJSON *child = cJSON_GetObjectItem(root, "characteristicsResource");
			int	nb = cJSON_GetArraySize(child);
			for(int i = 0; i < nb; i++){
				cJSON *item = cJSON_GetArrayItem(child, i);
				cJSON *id = cJSON_GetObjectItem(item,"id");
				if(id->type == cJSON_Number){
					cout << "carac: " << id->valueint << endl;
				}
			}
			
		} else {
		}
	}
	
	SECTION("Test import Characteristics_Tribe.json")
	{
		ifstream file (PATH_DATA"/Characteristics_Tribe.json", ios::in);
		if (file.is_open()){
			string str((std::istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
			
			file.close();

			cJSON *root = cJSON_Parse(str.c_str());
			
			cJSON *child = cJSON_GetObjectItem(root, "characteristicsTribe");
			int	nb = cJSON_GetArraySize(child);
			for(int i = 0; i < nb; i++){
				cJSON *item = cJSON_GetArrayItem(child, i);
				cJSON *id = cJSON_GetObjectItem(item,"id");
				if(id->type == cJSON_Number){
					cout << "carac: " << id->valueint << endl;
				}
			}
			
		} else {
		}
	}
	
	SECTION("Test import descriptionCharacteristics.json")
	{
		ifstream file (PATH_DATA"/descriptionCharacteristics.json", ios::in);
		if (file.is_open()){
			string str((std::istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
			
			file.close();

			cJSON *root = cJSON_Parse(str.c_str());
			
			cJSON *child = cJSON_GetObjectItem(root, "characteristics");
			int	nb = cJSON_GetArraySize(child);
			for(int i = 0; i < nb; i++){
				cJSON *item = cJSON_GetArrayItem(child, i);
				
				cJSON *id = cJSON_GetObjectItem(item,"id");
				if(id->type == cJSON_Number){
					cout << "id: " << id->valueint << endl;
				}
				
				cJSON *min = cJSON_GetObjectItem(item,"min");
				if(min->type == cJSON_Number){
					cout << "min: " << min->valueint << endl;
				}
				
				cJSON *max = cJSON_GetObjectItem(item,"max");
				if(max->type == cJSON_Number){
					cout << "max: " << max->valueint << endl;
				}
				
				cJSON *name = cJSON_GetObjectItem(item,"name");
				if(name->type == cJSON_String){
					cout << "name: " << name->valuestring << endl;
				}
				
				cJSON *definition = cJSON_GetObjectItem(item,"definition");
				if(definition->type == cJSON_String){
					cout << "definition: " << definition->valuestring << endl;
				}
				
				cJSON *type = cJSON_GetObjectItem(item,"type");
				if(type->type == cJSON_String){
					cout << "type: " << type->valuestring << endl;
				}
				
				cJSON *precision = cJSON_GetObjectItem(item,"precision");
				if(precision->type == cJSON_Number){
					cout << "precision: " << precision->valueint << endl;
				}
			}
			
		} else {
		}
	}
	
	SECTION("Test import descriptionItems.json")
	{
		ifstream file (PATH_DATA"/descriptionItems.json", ios::in);
		if (file.is_open()){
			string str((std::istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
			
			file.close();

			cJSON *root = cJSON_Parse(str.c_str());
			
			cJSON *child = cJSON_GetObjectItem(root, "items");
			int	nb = cJSON_GetArraySize(child);
			for(int i = 0; i < nb; i++){
				cJSON *item = cJSON_GetArrayItem(child, i);
				
				cJSON *name = cJSON_GetObjectItem(item,"name");
				if(name->type == cJSON_String){
					cout << "name: " << name->valuestring << endl;
				}
				
				cJSON *weight = cJSON_GetObjectItem(item,"weight");
				if(weight->type == cJSON_Number){
					cout << "weight: " << weight->valueint << endl;
				}
			}
			
		} else {
		}
	}
	
	SECTION("Test import nameListFemale.json")
	{
		ifstream file (PATH_DATA"/nameListFemale.json", ios::in);
		if (file.is_open()){
			string str((std::istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
			
			file.close();

			cJSON *root = cJSON_Parse(str.c_str());
			
			cJSON *child = cJSON_GetObjectItem(root, "nameList");
			int	nb = cJSON_GetArraySize(child);
			for(int i = 0; i < nb; i++){
				cJSON *item = cJSON_GetArrayItem(child, i);
				
				cJSON *name = cJSON_GetObjectItem(item,"name");
				if(name->type == cJSON_String){
					cout << "name: " << name->valuestring << endl;
				}
			}
			
		} else {
		}
	}
	
	SECTION("Test import nameListMale.json")
	{
		ifstream file (PATH_DATA"/nameListMale.json", ios::in);
		if (file.is_open()){
			string str((std::istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
			
			file.close();

			cJSON *root = cJSON_Parse(str.c_str());
			
			cJSON *child = cJSON_GetObjectItem(root, "nameList");
			int	nb = cJSON_GetArraySize(child);
			for(int i = 0; i < nb; i++){
				cJSON *item = cJSON_GetArrayItem(child, i);
				
				cJSON *name = cJSON_GetObjectItem(item,"name");
				if(name->type == cJSON_String){
					cout << "name: " << name->valuestring << endl;
				}
			}
			
		} else {
		}
	}
}
