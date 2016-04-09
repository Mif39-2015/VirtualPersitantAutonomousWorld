#include <iostream>
#include "Entity.hpp"

Entity::Entity(unsigned int i, std::string n) : pos(0, 0), id(i), name(n){}

int Entity::getId(){
	return id;
}

std::string Entity::getName(){
	return name;
}
Position Entity::getPos(){
    return pos;
}
std::map<Item, unsigned int> Entity::getInventory(){
    return inventory;
}

void Entity::setId(int i){
	id = i;
}

void Entity::setName(std::string n){
	name = n;
}

void Entity::setPos(int x, int y){
    pos = Position(x,y);
}

void Entity::setInventory(std::map<Item, unsigned int> inv){
    inventory = inv;
}


Entity::~Entity(void) {}