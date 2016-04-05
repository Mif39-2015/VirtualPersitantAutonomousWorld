#include <iostream>
#include "Building.hpp"

Building::Building(unsigned int i, std::string n, int x, int y, int z, int o, unsigned int sp) :
	Insentient_Entity(i, n), size(x, y, z), orientation(o), structural_point(sp){}

