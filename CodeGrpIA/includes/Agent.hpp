#ifndef AGENT_HPP
#define AGENT_HPP

#include <string>
#include <map>

#include "Sentient_Entity.hpp"

class Agent : public Sentient_Entity{

	public :
		//------------------ Constructeurs / Destructeurs------------------------
		Agent(int, int, int, int, int, int, int, bool, int, int, int, int, int, int, int, unsigned int, std::string);
		~Agent(void);
		//------------------ Accesseurs -----------------------------------------
		unsigned short int getIndependence();
		unsigned short int getCharisma();
		unsigned short int getCapacity();
		unsigned short int getStamina();
		unsigned short int getStamina_threshold();
		unsigned short int getSanity();
		//---------------- Mutateurs --------------------------------------------
		void setIndependence(int i);
		void setCharisma(int c);
		void setCapacity(int c);
		void setStamina(int s);
		void setStamina_threshold(int s);
		void setSanity(int s);


	protected :
		// caracteristics
		unsigned short int independence;
		unsigned short int charisma;
		unsigned short int capacity;
		unsigned short int stamina;
		unsigned short int stamina_threshold;
		unsigned short int sanity;

		//memory
		//std::map<std::string, std::string> map;
		//skills (Map)

};

#endif
