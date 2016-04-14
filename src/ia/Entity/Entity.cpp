#include <iostream>
#include "Entity/Entity.hpp"

unsigned int Entity::idCount = 0;

Entity::Entity(std::string n, type tid) : typeId(tid), name(n) {}

unsigned int Entity::getId(){
	return id;
}

std::string Entity::getName(){
	return name;
}

void Entity::setName(std::string n){
	name = n;
}

type Entity::getTypeId(){
    return typeId;
}

bool Entity::getModif(){
    return modif;
}

void Entity::setModif(bool m){
    modif = m;
}

Entity::~Entity(void) {}
