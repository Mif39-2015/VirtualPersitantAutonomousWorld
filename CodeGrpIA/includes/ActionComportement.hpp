#ifndef ACTIONCOMPORTEMENT_HPP
#define ACTIONCOMPORTEMENT_HPP

#include "Action.hpp"

class ActionComportement : Action {

	private :
		Comportement comportement;

	public :
		void Executer(Sentient_Entity * agent);
};

#endif
