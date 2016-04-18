#include <iostream>
#include "ia/Entity/Item.hpp"

std::vector<Item> Item::listItems;
Item::Item(std::string n, type t,std::map<int, int> charac) : Entity(n, t,charac){}

Item::~Item(){}

Item * Item::getItemByName(std::string n){
	for(unsigned int i = 0; i < Item::listItems.size(); i++){
		if(Item::listItems[i].getName() == n){
			return &Item::listItems[i];
		}
	}
	return nullptr;
}

int Item::loadItemsFile(std::string fileName){
	ifstream file (PATH_DATA"/descriptionItems.json", ios::in);
	if (file.is_open()){
		string str((std::istreambuf_iterator<char>(file)), istreambuf_iterator<char>());

		file.close();

		cJSON *root = cJSON_Parse(str.c_str());

		cJSON *child = cJSON_GetObjectItem(root, "items");
		int	nb = cJSON_GetArraySize(child);
		for(int i = 0; i < nb; i++){
			cJSON *item = cJSON_GetArrayItem(child, i);
			string nameItem = "";
			int weightItem = 0;

			cJSON *name = cJSON_GetObjectItem(item,"name");
			if(name->type == cJSON_String){
				//~ cout << "name: " << name->valuestring << endl;
				nameItem = name->valuestring;
			}

			cJSON *weight = cJSON_GetObjectItem(item,"weight");
			if(weight->type == cJSON_Number){
				//~ cout << "weight: " << weight->valueint << endl;
				weightItem = weight->valueint;
			}

			std::map<int, int> charact;
            charact.insert(std::pair<int, int>(19, weightItem));
			Item createdItem(nameItem, type::ID_ITEM, charact);
			listItems.push_back(createdItem);
		}

	} else {
		std::cout << "Unable to open general Item file" << std::endl;
		return -1;
	}
}
