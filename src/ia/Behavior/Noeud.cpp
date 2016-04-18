#include "ia/Behavior/Noeud.hpp"

// ******** CONSTRUCTEURS ********
Noeud::Noeud() {}
Noeud::Noeud(Action * a) : action(a) {}

// ******** GETTERS ********
vector<Arete *> Noeud::getAretesOut() {
	return aretesOut;
}
vector<Arete *> Noeud::getAretesIn() {
	return aretesIn;
}
Action * Noeud::getAction() {
	return action;
}

// ******** SETTERS ********
void Noeud::setAretesOut(vector<Arete *> aretesOut) {
	this->aretesOut = aretesOut;
}
void Noeud::setAretesIn(vector<Arete *> aretesIn) {
	this->aretesIn = aretesIn;
}
void Noeud::setAction(Action * a) {
	action = a;
}

// ******** AJOUTS ********
void Noeud::ajouterAreteOut(Arete * a) {
	aretesOut.push_back(a);
}
void Noeud::ajouterAreteIn(Arete * a) {
	aretesIn.push_back(a);
}

// ******** SUPPRESSION ********
void Noeud::supprimerAreteOut(Arete * a) {
	for (auto it = aretesOut.begin(); it != aretesOut.end(); ++it) {
		if (*it == a) {
			aretesOut.erase(it);
			return;
		}
	}
}
void Noeud::supprimerAreteIn(Arete * a) {
	for (auto it = aretesIn.begin(); it != aretesIn.end(); ++it) {
		if (*it == a) {
			aretesIn.erase(it);
			return;
		}
	}
}

// ******** FONTIONNEMENT ********
Noeud * Noeud::executerNoeud(Sentient_Entity * a, bool execAct) {
	for (auto it = aretesOut.begin() ; it != aretesOut.end(); ++it) {
		if ((*it)->isTrue(a)) return (*it)->getNoeudFin();
	}
	if (execAct) {
		action->Executer(a);
	}

	return this;
}
