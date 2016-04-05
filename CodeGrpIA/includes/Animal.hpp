#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

#include "Sentient_Entity.hpp"

class Animal : public Sentient_Entity{

	public : 
		Animal(int, bool, int, int, int, int, int, int, int, unsigned int, std::string);
		
		~Animal(void);
	
	private : 	

};

#endif
