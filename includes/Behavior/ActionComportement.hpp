#ifndef ACTIONCOMPORTEMENT_HPP
#define ACTIONCOMPORTEMENT_HPP

using namespace std;

#include "Behavior/Action.hpp"
#include <utility>

class Comportement;

class ActionComportement : Action {

	private :
		Comportement * comportement;

	public :
		void Executer(Sentient_Entity * agent);

		ActionComportement(){comportement = nullptr;};
		ActionComportement(Comportement * c) : comportement(c) {};

		Comportement * getComportement(){return comportement;}
		void setComportement(Comportement * c){comportement = c;}

};

#endif
