#include <iostream>
#include "ia/Entity/Tribe.hpp"

Tribe::Tribe(std::string n, unsigned int gi, type t, std::map<int, int> charac) : Entity(n, t, charac), goal_index(gi) {}

Tribe::~Tribe(){}

/*getters*/
unsigned int Tribe::getGoalIndex(){
    return goal_index;
}

/*setters*/
void Tribe::setGoalIndex(unsigned int _goal_index){
    goal_index=_goal_index;
    setModif(true);
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
    setModif(true);
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
        if(a->getTypeId() == type::ID_RESSOURCE_BOIS
            || a->getTypeId() == type::ID_RESSOURCE_PIERRE
            || a->getTypeId() == type::ID_RESSOURCE_METAL
            || a->getTypeId() == type::ID_RESSOURCE_VIANDE
            || a->getTypeId() == type::ID_RESSOURCE_LEGUME){
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
    setModif(true);
}

void Tribe::afficheStock(){
	for(auto it = stock.begin(); it != stock.end(); it++){
		cout << it->first->getName() << ", " << it->second << endl;
	}
}

void Tribe::afficheMembres()
{
	for(auto it = members.begin(); it != members.end(); it++)
	{
		(*it)->affiche();
	}
}

void Tribe::affiche(){}

cJSON* Tribe::toJson(){
	cJSON *entity = Entity::toJson();
	cJSON_AddNumberToObject(entity, "goal_index", this->goal_index);

	//ajout des membres de la tribu dans le JSON
	cJSON * members_list;
	members_list = cJSON_CreateArray();

	for(auto it = members.begin(); it != members.end(); it++){
		cJSON* member = cJSON_CreateObject();
		cJSON_AddNumberToObject(member, "id", (*it)->getId());
		cJSON_AddStringToObject(member, "type", TypeNames[(*it)->getTypeId()]);
		cJSON_AddItemToArray(members_list, member);
	}

	cJSON_AddItemToObject(entity,"members", members_list);

	//ajout des items possédés par la tribu dans le JSON
	cJSON * items;
	items = cJSON_CreateArray();

	for(auto it2 = stock.begin(); it2 != stock.end(); it2++){
		cJSON* item = cJSON_CreateObject();
		cJSON_AddNumberToObject(item, (it2->first->getName()).c_str(),it2->second);
		cJSON_AddItemToArray(items, item);
	}

	cJSON_AddItemToObject(entity,"items", items);

	return entity;
}
