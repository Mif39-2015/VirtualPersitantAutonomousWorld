#include <iostream>
#include "Entity/Tangible_Entity.hpp"

Tangible_Entity::Tangible_Entity(std::string s, type s2,std::map<int, int> charac, Position p) :
    Entity(s, s2, charac), pos(p) {
}

Position Tangible_Entity::getPos(){
    return pos;
}

std::map<Item, unsigned int> Tangible_Entity::getInventory(){
    return inventory;
}

void Tangible_Entity::setPos(int x, int y){
    pos = Position(x,y);
}

void Tangible_Entity::setInventory(std::map<Item, unsigned int> inv){
    inventory = inv;
}
