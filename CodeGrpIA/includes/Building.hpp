#ifndef BUILDING_HPP
#define BUILDING_HPP

#include "Insentient_Entity.hpp"
#include "Triple.hpp"

class Building : public Insentient_Entity{

public:
	Triple size;
	std::map<Item, int> recipe;

	Building(unsigned int i, std::string n, int x, int y, int z, int o, unsigned int sp);

	~Building(void){};

private:
	int orientation; //A voir si on le garde
	unsigned int structural_point;

};

#endif
