#ifndef ACTIONSIMPLE_HPP
#define ACTIONSIMPLE_HPP

using namespace std;

#include "Action.hpp"
#include "FonctionAction.hpp"

class ActionSimple : Action {

	private :
		//~ void (*Sentient_Entity::function1)(Sentient_Entity * agent);
		//~ void (*Sentient_Entity::function2)(Sentient_Entity * agent, Entity * e);

		//~ Fonction_Action fA;
		//~ vector<Fonction_Entite> vfE;

	public :
		void Executer(Sentient_Entity * agent);
};

#endif
