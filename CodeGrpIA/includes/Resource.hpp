#ifndef RESOURCE_HPP
#define RESOURCE_HPP

#include "Insentient_Entity.hpp"

class Resource : public Insentient_Entity{

public:
	Resource(unsigned int rr, unsigned int rv, unsigned int i, std::string n);

private:
	//Every respawn_rate tick on the clock, the resouces regain respawn_value unit
	//The total of Item of the resource is stocked in the inventory (in the Entity class)
	unsigned int respawn_rate;
	unsigned int respawn_value;

};

#endif
