#include "Arete.hpp"

Arete::Arete(Noeud * nD, Noeud * nF, vector<Fonction_Bool> fC) : noeudDepart(nD) , noeudFin(nF) {
	//~ conditions = fC;
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

//~ void Arete::ajouterCondition(bool (*f)){
	//~ conditions.push_back(f);
//~ }
//~
//~ void Arete::ajouterCondition(vector<bool (*)> vC){
	//~ for( size_t i=0; i<vC.size(); ++i){
		//~ conditions.push_back(vC[i]);
	//~ }
//~ }

