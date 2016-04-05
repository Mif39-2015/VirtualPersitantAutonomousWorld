#ifndef SENTIENT_ENTITY_HPP
#define SENTIENT_ENTITY_HPP

#include <string>
#include <map>

#include "Entity.hpp"

class Sentient_Entity : public Entity{

	public : 
		
		Sentient_Entity(int, bool, int, int , int ,int, int , int, int, unsigned int, std::string);
		
		//destructor ?

	private :
		int vitality;
		bool gender;
		int age;
		int agressiveness;
		int fitness;
		int satiety;
		int satiety_threshold;
		int reflex;
		int perception;
		//job 
	
	

};

#endif
