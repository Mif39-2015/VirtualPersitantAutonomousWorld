#include <iostream>
#include "ia/Entity/Tangible_Entity.hpp"

Tangible_Entity::Tangible_Entity(std::string s, type s2,std::map<int, int> charac, Position p) : Entity(s, s2, charac), pos(p) {}

Position Tangible_Entity::getPos(){
    return pos;
}

void Tangible_Entity::setPos(int x, int y){
    pos = Position(x,y);
    setModif(true);
}

int Tangible_Entity::getQuantityByItem(Item* i){
    return stock.at(i);
}

// Pour ajouter des itemms à un inventaire, il faut utiliser l'adresse de sa case dans la liste globale
void Tangible_Entity::addItemToStock(Item* i, int quantity){
    if(stock.find(i)==stock.end())
        stock.insert(std::pair<Item*, int>(i, quantity));
    else
        stock.at(i)=stock.find(i)->second+quantity;
    setModif(true);
}

void Tangible_Entity::afficheStock(){
	for(auto it = stock.begin(); it != stock.end(); it++){
		cout << it->first->getName() << ", " << it->second << endl;
	}
}

void Tangible_Entity::removeItemFromStock(Item * i, int quantity){
    for(auto it = stock.begin(); it != stock.end(); it++){
        if(it->first == i){
            it->second = it->second - quantity;
            if(it->second < 0) it->second = 0;
            setModif(true);
        }
    }
}

cJSON* Tangible_Entity::toJson()
{
	cJSON *entity = Entity::toJson();

	//ajout de la position
	//cJSON_AddItemToObject(entity, "position", pos.toJson());

	//ajout des items
	cJSON * items;
	items = cJSON_CreateArray();

	for(auto it = stock.begin(); it != stock.end(); it++){
		cJSON* item = cJSON_CreateObject();
		cJSON_AddNumberToObject(item, (it->first->getName()).c_str(),it->second);
		cJSON_AddItemToArray(items, item);
	}

	cJSON_AddItemToObject(entity,"items", items);

	return entity;
}

void Tangible_Entity::affiche(){}
