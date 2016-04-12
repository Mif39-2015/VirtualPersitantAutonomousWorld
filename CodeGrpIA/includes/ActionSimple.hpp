#ifndef ACTIONSIMPLE_HPP
#define ACTIONSIMPLE_HPP

using namespace std;

#include "Action.hpp"
#include "FonctionAction.hpp"

class ActionSimple : Action {
	private :

		Fonction_Action_Simple fAS;
		Fonction_Action_Parametre fAP;

		vector<Fonction_Action_Parametre_Retour> fAPR;
		Entity * parametreFinal;

	public :
		void Executer(Sentient_Entity * agent);
};

#endif
