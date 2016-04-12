/*
#ifndef BUILDING_HPP
#define BUILDING_HPP

#include "Insentient_Entity.hpp"
#include "Vector3.hpp"

class Building : public Insentient_Entity{

public:
	Vector3 size;
	std::map<Item, int> recipe;

	Building(int x, int y, int z, int o, unsigned int sp, std::string n, std::string tid);

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
*/
