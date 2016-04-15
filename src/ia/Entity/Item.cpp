#include <iostream>
#include "Entity/Item.hpp"

std::vector<Item> ItemList::listItems;
Item::Item(std::string n, type t,std::map<int, int> charac) : Entity(n, t,charac){}

Item::~Item(){}

int ItemList::loadItemsFile(std::string fileName){
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
			ItemList::listItems.push_back(createdItem);
		}
		
	} else {
		std::cout << "Unable to open general Item file" << std::endl;
		return -1;
	}
	//~ std::string line;
	//~ std::ifstream myfile (fileName, std::ios::in);
	//~ if (myfile.is_open())
	//~ {
        //~ while(std::getline(myfile,line))
        //~ {
            //~ std::cout << line << '\n';
            //~ vector<std::string> resline = cutString(line, ";");
            //~ std::map<int, int> charact;
            //~ charact.insert(std::pair<int, int>(19, std::stoi(resline[1])));
            //~ string name = resline[0];
            //~ Item item(name, type::ID_ITEM, charact);
            //~ 
//~ 
            //~ ItemList::listItems.push_back(item);
        //~ }
        //~ myfile.close();
	//~ }
//~ 
	//~ else{
		//~ std::cout << "Unable to open general Item file" << std::endl;
		//~ return -1;
	//~ }
}
