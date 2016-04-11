#include <iostream>
#include "Building.hpp"

Building::Building(unsigned int i, std::string n, int x, int y, int z, int o, unsigned int sp) :
	Insentient_Entity(i, n), size(x, y, z), orientation(o), structural_point(sp){}

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
