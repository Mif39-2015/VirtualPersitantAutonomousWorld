#include "Behavior/Comportement.hpp"
#include "Behavior/ActionComportement.hpp"

void ActionComportement::Executer(Sentient_Entity * agent) {
	agent->addToTrace(comportement, comportement->getNoeudDepart(), true);
}
