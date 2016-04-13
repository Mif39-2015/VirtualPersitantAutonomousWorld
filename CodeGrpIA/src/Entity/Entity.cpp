#include <iostream>
#include "Entity/Entity.hpp"

unsigned int Entity::idCount = 0;

Entity::Entity(std::string n, int tid) : typeId(tid), name(n), pos(0, 0){}

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
int Entity::getTypeId(){
    return typeId;
}
void Entity::setInventory(std::map<Item, unsigned int> inv){
    inventory = inv;
}

bool Entity::getModif(){
    return modif;
}

void Entity::setModif(bool m){
    modif = m;
}

Entity::~Entity(void) {}
