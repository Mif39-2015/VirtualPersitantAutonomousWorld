#include <iostream>
#include "Entity.hpp"

Entity::Entity(unsigned int i, std::string n) : pos(0, 0), id(i), name(n){}

Entity::~Entity(void) {}


