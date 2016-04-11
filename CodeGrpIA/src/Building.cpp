#include <iostream>
#include "Building.hpp"
#include <sstream>

unsigned int Building::idCount = 0;

Building::Building(std::string n, int x, int y, int z, int o, unsigned int sp) :
	Insentient_Entity(n), orientation(o), structural_point(sp){
		size.x = x;
		size.y = y;
		size.z = z;

		std::stringstream ss;
		ss << "buil_" << Building::idCount;
		id = ss.str();
		std::cout << id << std::endl;
		Building::idCount++;
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