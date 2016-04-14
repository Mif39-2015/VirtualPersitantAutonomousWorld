#ifndef ACTION_HPP
#define ACTION_HPP

using namespace std;

#include "Entity/Sentient_Entity.hpp"
//~ #include "Behavior/Comportement.hpp"

// class Sentient_Entity;

class Action {
	public :
		virtual void Executer(Sentient_Entity * agent){};
};

#endif
