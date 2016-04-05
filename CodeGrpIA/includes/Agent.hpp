#ifndef AGENT_HPP
#define AGENT_HPP

#include <string>
#include <map>

#include "Sentient_Entity.hpp"

class Agent : public Sentient_Entity{

	public : 
		Agent(int, int, int, int, int, int, int, bool, int, int, int, int, int, int, int, unsigned int, std::string);
		
		~Agent(void);
	
	private : 
		// caracteristics
		int independence;
		int charisma;
		int capacity;
		int stamina;
		int stamina_threshold;
		int sanity;
		
		//memory
		//std::map<std::string, std::string> map;
		//skills (Map)		

};

#endif
