#ifndef ACTION_HPP
#define ACTION_HPP

using namespace std;

#include "Sentient_Entity.hpp"
#include "Comportement.hpp"

class Action {
	public :
		virtual void Executer(Sentient_Entity * agent){};
};

#endif
