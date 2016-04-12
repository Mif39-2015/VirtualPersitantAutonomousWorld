#ifndef ACTIONCOMPORTEMENT_HPP
#define ACTIONCOMPORTEMENT_HPP

using namespace std;

#include "Action.hpp"
//~ #include "Comportement.hpp"
#include <utility>

class Comportement;

class ActionComportement : Action {

	private :
		Comportement * comportement;

	public :
		void Executer(Sentient_Entity * agent);
};

#endif
