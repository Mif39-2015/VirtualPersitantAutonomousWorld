#ifndef BUILDING_HPP
#define BUILDING_HPP

#include "Insentient_Entity.hpp"
#include "Vector3.hpp"

class Building : public Insentient_Entity{

public:
	Vector3 size;
	std::map<Item, int> recipe;

	Building(std::string n, int x, int y, int z, int o, unsigned int sp);

	//getters
	int getOrientation();
	int getStructuralPoint();
	
	//setters
	void setOrientation(int _newOrientation);
	void setStructurationPoint(int _newStructurationPoint);

	//destruct
	~Building(void){};

protected:
	static unsigned int idCount;
	int orientation; //A voir si on le garde
	unsigned int structural_point;

};

#endif
