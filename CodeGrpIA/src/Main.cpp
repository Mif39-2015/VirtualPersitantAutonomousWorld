#include <iostream>

#include "Characteristics.hpp"
#include "Factories.hpp"
#include "Comportement.hpp"
#include "Sentient_Entity.hpp"

void scenario(){
    std::string name = "Mykaz";
    std::string tid = "agent";
    Sentient_Entity* agent = new Sentient_Entity(Position(0, 0),name,tid);

    Comportement comp;
    Noeud noeudPasFaim;
    Noeud noeudFaim;

    std::vector<Fonction_Bool> vectFctTrue;
    vectFctTrue.push_back(Fonction_BOOL_TRUE);
    Arete areteTrue(&noeudPasFaim,&noeudFaim,vectFctTrue);

    std::vector<Fonction_Bool> vectFctFalse;
    vectFctFalse.push_back(Fonction_BOOL_FALSE);
    Arete areteFalse(&noeudFaim,&noeudPasFaim,vectFctFalse);

    noeudPasFaim.addAreteIn(&areteFalse);
    noeudPasFaim.addAreteOut(&areteTrue);
    noeudFaim.addAreteIn(&areteTrue);
    noeudFaim.addAreteOut(&areteFalse);

    Noeud* noeudCourant = &noeudPasFaim;

    comp.ajouterNoeud(&noeudPasFaim);
    comp.ajouterNoeud(&noeudFaim);

    for(int i = 0; i < 5; i++){
	    std::cout << "Noeud courant : " << noeudCourant << std::endl;
	    noeudCourant = noeudCourant->executerNoeud(agent);
	}
}

int main(int argc, char const *argv[])
{

    scenario();

    return 0;
}
