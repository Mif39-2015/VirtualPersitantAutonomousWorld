#include <iostream>
#include "Entity/Item.hpp"

Item::Item(unsigned int i, std::string n, float w) : id(i), name(n), weight(w){}

const unsigned int& Item::getID() //ref ou pas ref ?
{
	return this->id;
}

const std::string& Item::getName()
{
	return this->name;
}

const float& Item::getWeight()
{
	return this->weight;
}

Item::~Item(){}
