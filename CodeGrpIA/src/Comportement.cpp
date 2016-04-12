#include "Comportement.hpp"

Comportement::Comportement(){}

Comportement::Comportement(vector<Noeud*> vN, Noeud * nD, vector<Noeud*> nFs) : noeuds(vN), noeudDepart (nD), noeudsFin(nFs) {}

void Comportement::ajouterNoeud(Noeud * n){
	noeuds.push_back(n);
}

void Comportement::supprimerNoeud(Noeud * n){
	for (std::vector<Noeud *>::iterator it = noeuds.begin() ; it != noeuds.end(); ++it){
		if(*it == n) noeuds.erase(it);
	}
}

void Comportement::setNoeudDepart(Noeud * nD){
	noeudDepart = nD;
}

void Comportement::setNoeudFin(vector<Noeud *> nFs){
	noeudsFin = nFs;
}

Noeud * Comportement::getNoeudDepart(){
	return noeudDepart;
}

vector<Noeud *> Comportement::getNoeudFin(){
	return noeudsFin;
}

