#ifndef ACTIONSIMPLE_HPP
#define ACTIONSIMPLE_HPP

using namespace std;

#include "Action.hpp"
#include "FonctionEnums.hpp"

#include <stack>

class ActionSimple : Action {
	private :

		FONC_VOID fV = FONC_V_NULL;
		FONC_VOID_ENTITY fVE = FONC_V_E_NULL;

		stack<FONC_ENTITY_ENTITY> sFEE;
		Entity * parametreFinal;

	public :
		void Executer(Sentient_Entity * agent);
};

#endif
