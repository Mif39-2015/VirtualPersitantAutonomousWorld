#include <iostream>
#include "Resource.hpp"
#include <sstream>

unsigned int Resource::idCount = 0;

Resource::Resource(unsigned int rr, unsigned int rv, std::string n, std::string tid)
	: Insentient_Entity(n, tid), respawn_rate(rr), respawn_value(rv)
{
	// std::stringstream ss;
	// ss << "res_" << Resource::idCount;
	id = Entity::idCount;
	// std::cout << id << std::endl;
	Entity::idCount++;
}

