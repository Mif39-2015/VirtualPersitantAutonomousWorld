#ifndef ACTIONSIMPLE_HPP
#define ACTIONSIMPLE_HPP

#include "Action.hpp"

class ActionSimple : Action {

	private :
		//~ void (*Sentient_Entity::function1)(Sentient_Entity * agent);
		//~ void (*Sentient_Entity::function2)(Sentient_Entity * agent, Entity * e);

	public :
		void Executer(Sentient_Entity * agent);
};

#endif
