#include "Arete.hpp"

Arete::Arete(Noeud * nD, Noeud * nF, vector<Fonction_Bool> fC) : noeudDepart(nD) , noeudFin(nF) {
	conditions_Simples = fC;
}

void Arete::setNoeudDepart(Noeud * nD){
	noeudDepart = nD;
}

void Arete::setNoeudFin(Noeud * nF){
	noeudFin = nF;
}

Noeud * Arete::getNoeudDepart(){
	return noeudDepart;
}

Noeud * Arete::getNoeudFin(){
	return noeudFin;
}

bool Arete::isTrue(Sentient_Entity * a){
	for(auto it=conditions_Simples.begin(); it!=conditions_Simples.end(); ++it){
		if(!FonctionCondition::mapFonctionsBool[*it](a)) return false;
	}
	return true;
}
