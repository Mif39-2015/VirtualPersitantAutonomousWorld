#include "ia/Behavior/Comportement.hpp"
#include "ia/Behavior/Action.hpp"

void ActionComportement::Executer(Sentient_Entity * agent) {
	agent->addToTrace(comportement, comportement->getNoeudDepart(), true);
}

void ActionSimple::Executer(Sentient_Entity * agent) {
	if (fV != FONC_V_NULL) {
		MapEnumPointeur::mapFoncVoid[fV](agent);
	}
	else {
		Entity * e = nullptr;
		while (!sFEE.empty()) {
			e = MapEnumPointeur::mapFoncEntityEntity[sFEE.top()](agent, e);
			sFEE.pop();
		}
		MapEnumPointeur::mapFoncVoidEntity[fVE](agent, e);
	}
}
