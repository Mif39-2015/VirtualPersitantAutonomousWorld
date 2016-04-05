#include <iostream>
#include "Item.hpp"

Item::Item(unsigned int i, std::string n, float w) : id(i), name(n), weight(w){}

Item::~Item(){}
