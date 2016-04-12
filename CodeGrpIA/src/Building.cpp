/*
#include <iostream>
#include "Building.hpp"
#include <sstream>

unsigned int Building::idCount = 0;

Building::Building(int x, int y, int z, int o, unsigned int sp, std::string n, std::string tid) :
	Insentient_Entity(n, tid), orientation(o), structural_point(sp){
		size.x = x;
		size.y = y;
		size.z = z;

		id = Entity::idCount;
		Entity::idCount++;
	}

	//getters
	int Building::getOrientation(){
		return orientation;
	}

	int Building::getStructuralPoint(){
		return structural_point;
	}

	//setters
	void Building::setOrientation(int _newOrientation){
			orientation = _newOrientation;
	}
	void Building::setStructurationPoint(int _newStructurationPoint){
		structural_point = _newStructurationPoint;
	}

//test avec ssh malik
*/
