#include <iostream>
#include "ia/Entity/Tangible_Entity.hpp"

Tangible_Entity::Tangible_Entity(std::string s, type s2,std::map<int, int> charac, Position p) : Entity(s, s2, charac), pos(p) {}

Position Tangible_Entity::getPos(){
    return pos;
}

void Tangible_Entity::setPos(int x, int y){
    pos = Position(x,y);
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
}

void Tangible_Entity::afficheStock(){
	for(auto it = stock.begin(); it != stock.end(); it++){
		cout << it->first->getName() << ", " << it->second << endl;
	}
}
