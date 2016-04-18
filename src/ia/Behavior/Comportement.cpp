#include "Behavior/Comportement.hpp"
#include "Tools/Tools.hpp"

// ******** CONSTRUCTEURS ********
Comportement::Comportement() {}
Comportement::Comportement(vector<Noeud *> noeuds) : noeuds(noeuds) {}
Comportement::Comportement(vector<Noeud *> noeuds, Noeud * noeudDepart, Noeud * noeudFin): noeuds(noeuds), noeudDepart(noeudDepart) {
	noeudsFin.push_back(noeudFin);
}
Comportement::Comportement(vector<Noeud *> noeuds, Noeud * noeudDepart, vector<Noeud *>noeudFin) : noeuds(noeuds), noeudDepart(noeudDepart), noeudsFin(noeudFin) {}

// ******** DESTRUCTEURS ********
Comportement::~Comportement() {
	cout << "On est dans le destructeur du comportement" << this << endl << "il a " << noeuds.size() << " noeuds" << endl;
	for (size_t i = 0; i < noeuds.size(); ++i) {
		cout << "on delete le noeud " << noeuds[i] << endl;
		delete (noeuds[i]);
	}
}

// ******** GETTERS ********
vector<Noeud *> Comportement::getNoeuds() {
	return noeuds;
}
Noeud * Comportement::getNoeudDepart() {
	return noeudDepart;
}
vector<Noeud *> Comportement::getNoeudFin() {
	return noeudsFin;
}

// ******** SETTERS ********
void Comportement::setNoeuds(vector<Noeud *> noeuds) {
	this->noeuds = noeuds;
}
void Comportement::setNoeudDepart(Noeud * noeud) {
	noeudDepart = noeud;
}
void Comportement::setNoeudFin(vector<Noeud *> noeudFin) {
	noeudsFin = noeudFin;
}

// ******** AJOUTS ********
void Comportement::ajouterNoeud(Noeud * n) {
	noeuds.push_back(n);
}
void Comportement::ajouterNoeudFin(Noeud * n) {
	if (findInVector(noeuds, n) == -1) {
		noeuds.push_back(n);
	}
	noeudsFin.push_back(n);
}

// ******** SUPPRESSION ********
void Comportement::supprimerNoeud(Noeud *n) {
	supprimerNoeudFin(n);
	for (auto it = noeuds.begin(); it != noeuds.end(); ++it) {
		if (*it == n) {
			noeuds.erase(it);
			return;
		}
	}
}
void Comportement::supprimerNoeudFin(Noeud * n) {
	for (auto it = noeudsFin.begin(); it != noeudsFin.end(); ++it) {
		if ( *it == n) {
			noeudsFin.erase(it);
			return;
		}
	}
}
