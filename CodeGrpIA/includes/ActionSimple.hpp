#ifndef ACTIONSIMPLE_HPP
#define ACTIONSIMPLE_HPP

#include "Action.hpp"

class ActionSimple : Action {

	private :
		void (*function)(...);

	public :
		void Executer(Sentient_Entity * agent);
};

#endif
