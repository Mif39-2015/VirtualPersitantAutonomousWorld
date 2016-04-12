#include <iostream>
#include "Entity.hpp"

unsigned int Entity::idCount = 0;

Entity::Entity(std::string n, std::string tid) : typeId(tid), name(n), pos(0, 0){}

unsigned int Entity::getId(){
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

void Entity::setName(std::string n){
	name = n;
}

void Entity::setPos(int x, int y){
    pos = Position(x,y);
}
std::string Entity::getTypeId(){
    return typeId;
}
void Entity::setInventory(std::map<Item, unsigned int> inv){
    inventory = inv;
}


Entity::~Entity(void) {}
