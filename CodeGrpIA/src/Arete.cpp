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
	for(auto it=condition_Complexes.begin(); it!=condition_Complexes.end(); ++it){
		int val1 = FonctionCondition::mapFonctionsInt[it->fonc1](a,it->e1);
		int val2;
		if(it->fonc2!=FONC_NULL)
			val2 = FonctionCondition::mapFonctionsInt[it->fonc2](a,it->e2);
		else
			val2 = it->comp;
		switch (it->op){
			case Inf :
				if(!val1<val2) return false;
				break;
			case Inf_Eg :
				if(!val1<=val2) return false;
				break;
			case Eg :
				if(!val1==val2) return false;
				break;
			case Sup_Eg :
				if(!val1>=val2) return false;
				break;
			case Sup :
				if(!val1>val2) return false;
				break;
			default :
				break;
		}
	}
	return true;
}
