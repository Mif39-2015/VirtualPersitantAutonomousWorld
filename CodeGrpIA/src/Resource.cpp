#include <iostream>
#include "Resource.hpp"

Resource::Resource(unsigned int rr, unsigned int rv, unsigned int i, std::string n)
	: Insentient_Entity(i, n), respawn_rate(rr), respawn_value(rv)
{}

