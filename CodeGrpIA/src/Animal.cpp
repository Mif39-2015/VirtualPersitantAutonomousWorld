#include <iostream>
#include <sstream>
#include "Animal.hpp"

unsigned int Animal::idCount = 0;

Animal::Animal(int v, bool g, int a, int agr , int f ,int s, int s_t, int r, int p, std::string n):Sentient_Entity(v, g, a, agr, f, s, s_t, r, p,n){
	std::stringstream ss;
	ss << "ag_" << Animal::idCount;
	id = ss.str();
	std::cout << id << std::endl;
	Animal::idCount++;
}

Animal::~Animal(void){}
