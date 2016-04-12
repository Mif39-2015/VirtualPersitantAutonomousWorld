#ifndef ACTION_HPP
#define ACTION_HPP

#include "Sentient_Entity.hpp"
#include "Comportement.hpp"

using namespace std;

class Action {
	public :
		virtual void Executer(Sentient_Entity * agent){};
};

#endif
