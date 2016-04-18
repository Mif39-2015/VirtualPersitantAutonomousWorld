#include "ia/Behavior/Comportement.hpp"
#include "ia/Behavior/ActionComportement.hpp"

void ActionComportement::Executer(Sentient_Entity * agent) {
	agent->addToTrace(comportement, comportement->getNoeudDepart(), true);
}
