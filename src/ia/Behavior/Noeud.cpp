#include "Behavior/Noeud.hpp"

Noeud::Noeud(Noeud* n) : aretesOut(n->aretesOut), aretesIn(n->aretesIn), action(n->action) {}

void Noeud::setAction(Action * a) {
    action = a;
}

Action * Noeud::getAction() {
    return action;
}
vector<Arete*> Noeud::getAretesIn() {
    return aretesIn;
}

void Noeud::setAretesIn(vector<Arete*> aretesIn) {
    this->aretesIn = aretesIn;
}

vector<Arete*> Noeud::getAretesOut() {
    return aretesOut;
}

void Noeud::setAretesOut(vector<Arete*> aretesOut) {
    this->aretesOut = aretesOut;
}

Noeud * Noeud::executerNoeud(Sentient_Entity * a, bool execAct) {
    for (auto it = aretesOut.begin() ; it != aretesOut.end(); ++it) {
        if ((*it)->isTrue(a)) return (*it)->getNoeudFin();
    }
    if (execAct) {
        action->Executer(a);
    }

    return this;
}

void Noeud::addAreteIn(Arete * a) {
    aretesIn.push_back(a);
}

void Noeud::addAreteOut(Arete * a) {
    aretesOut.push_back(a);
}

void Noeud::delAreteIn(Arete * a) {
    for (std::vector<Arete *>::iterator it = aretesIn.begin(); it != aretesIn.end(); it++) {
        if ((*it) == a) { aretesIn.erase(it); break;}
    }
}

void Noeud::delAreteOut(Arete * a) {
    for (std::vector<Arete *>::iterator it = aretesOut.begin(); it != aretesOut.end(); it++) {
        if ((*it) == a) { aretesOut.erase(it); break;}
    }
}
