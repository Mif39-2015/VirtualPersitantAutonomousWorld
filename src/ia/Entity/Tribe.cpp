#include <iostream>
#include "Entity/Tribe.hpp"

Tribe::Tribe(std::string n, unsigned int gi, type t, std::map<int, int> charac) : Entity(n, t, charac), goal_index(gi) {}

/*getters*/
unsigned int Tribe::getGoalIndex(){
    return goal_index;
}

/*setters*/
void Tribe::setGoalIndex(unsigned int _goal_index){
    goal_index=_goal_index;
}
int Tribe::getTribeSize(){
    int sizet=0;
    for(Entity* a : tribe){
        sizet++;
    }
    return sizet;
}
void Tribe::addNewEntity(Entity* a){
            tribe.push_back(a);
}
int Tribe::getPopulationSize(){
    int sizet=0;
    for(Entity* a: tribe){
        //if(a.getTypeId().compare("agent")==0){
        if(a->getTypeId()==ID_AGENT){
            sizet++;
        }
    }
    return sizet;
}
int Tribe::getNbBuildings(){
    int sizet=0;
    for(Entity* a: tribe){
        if(a->getTypeId()==ID_BUILDING){
            sizet++;
        }
    }
    return sizet;
}
int Tribe::getNbRessources(){
    int sizet=0;
    for(Entity* a: tribe){
        if(a->getTypeId()==ID_RESSOURCE){
            sizet++;
        }
    }
    return sizet;
}
int Tribe::getQuantityByItem(Item* i){
    return stock.at(i);
}
void Tribe::addItemToStock(Item* i, int quantity){
    if(stock.find(i)==stock.end())
        stock.insert(std::pair<Item*, int>(i, quantity));
    else
        stock.at(i)=stock.find(i)->second+quantity;
}

cJSON* Tribe::toJson(){
	cJSON *entity = Entity::toJson();
	/*cJSON_AddNumberToObject(root, "goal_index", this->goal_index);
	
	cJSON_CreateArray(ids,4);
	cJSON *members;
	members = cJSON_CreateArray();
	
	for(auto it = tribe.begin(); it != tribe.end(); it++){
		cJSON_AddItemToArray(members, *(it)->toJson());
	}
	
	cJSON_AddItemToObject(entity,"members", members);
	
	items = cJSON_CreateArray();
	
	for(auto it = stock.begin(); it != stock.end(); it++){
		cJSON_AddItemToArray(members, *(it)->toJson());
	}
	
	cJSON_AddItemToObject(entity,"members", members);
		
		
	cJSON *root;
	root = cJSON_CreateObject();
	cJSON_AddNumberToObject(root, "id", this->id);
	cJSON_AddStringToObject(root, "typeId", TypeNames[this->typeId]);
	cJSON_AddStringToObject(root, "name", this->name.c_str());
	cout << cJSON_Print(root) << endl;*/
	
	return entity;
}
