#include "Noeud.hpp"

Noeud::Noeud() {}
Noeud::Noeud(Action* a) : action(a){}
Noeud::Noeud(Noeud* n) : aretesOut(n->aretesOut), aretesIn(n->aretesIn), action(n->action){}

void Noeud::setAction(Action * a) {
    action = a;
}

Action * Noeud::getAction(){
    return action;
}
vector<Arete*> Noeud::getAretesIn(){
    return aretesIn;
}

void Noeud::setAretesIn(vector<Arete*> aretesIn) {
    this->aretesIn = aretesIn;
}

vector<Arete*> Noeud::getAretesOut(){
    return aretesOut;
}

void Noeud::setAretesOut(vector<Arete*> aretesOut) {
    this->aretesOut = aretesOut;
}

Noeud * Noeud::executerNoeud(Sentient_Entity * a){
    for (std::vector<Arete *>::iterator it = aretesOut.begin() ; it != aretesOut.end(); ++it){
        if((*it)->isTrue(a)) return (*it)->getNoeudFin();
    }
    // action->Executer(a);
    return this;
 }
