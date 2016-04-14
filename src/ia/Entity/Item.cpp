#include <iostream>
#include "Entity/Item.hpp"

Item::Item(std::string n, type t,std::map<int, int> charac) : Entity(n, t,charac){}

Item::~Item(){}
