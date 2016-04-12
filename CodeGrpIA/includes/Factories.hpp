#ifndef FACTORIES_HPP
#define FACTORIES_HPP

#include <fstream>
#include <iostream>
#include "Characteristics.hpp"
#include "Sentient_Entity.hpp"
#include "Tools.hpp"

class Factories{

public:

	//Factories permettant de créer les entités conscientes

	static Sentient_Entity * createAgent();
	
	static Sentient_Entity * createAnimal();

};

#endif
