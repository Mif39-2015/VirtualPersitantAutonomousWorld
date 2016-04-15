#include <iostream>
#include "Entity/Tribe.hpp"

Tribe::Tribe(std::string n, unsigned int gi, type t, std::map<int, int> charac) : Entity(n, t, charac), goal_index(gi) {}

Tribe::~Tribe(){}

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
    for(Entity* a : members){
        sizet++;
    }
    return sizet;
}
void Tribe::addNewEntity(Entity* a){
    members.push_back(a);
}
int Tribe::getPopulationSize(){
    int sizet=0;
    for(Entity* a: members){
        if(a->getTypeId()==ID_AGENT){
            sizet++;
        }
    }
    return sizet;
}
int Tribe::getNbBuildings(){
    int sizet=0;
    for(Entity* a: members){
        if(a->getTypeId()==ID_BUILDING){
            sizet++;
        }
    }
    return sizet;
}
int Tribe::getNbRessources(){
    int sizet=0;
    for(Entity* a: members){
        if(a->getTypeId()==ID_RESSOURCE){
            sizet++;
        }
    }
    return sizet;
}
int Tribe::getQuantityByItem(Item* i){
    return stock.at(i);
}
// Pour ajouter des itemms à un inventaire, il faut utiliser l'adresse de sa case dans la liste globale
void Tribe::addItemToStock(Item* i, int quantity){
    if(stock.find(i)==stock.end())
        stock.insert(std::pair<Item*, int>(i, quantity));
    else
        stock.at(i)=stock.find(i)->second+quantity;
}

void Tribe::afficheStock(){
	for(auto it = stock.begin(); it != stock.end(); it++){
		cout << it->first->getName() << ", " << it->second << endl;
	}
}

cJSON* Tribe::toJson(){
	cJSON *entity = Entity::toJson();
	/*cJSON_AddNumberToObject(root, "goal_index", this->goal_index);

	cJSON_CreateArray(ids,4);
	cJSON *members;
	members = cJSON_CreateArray();

	for(auto it = tribe.begin(); it != members.end(); it++){
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
