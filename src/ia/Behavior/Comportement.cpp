#include "ia/Behavior/Comportement.hpp"
#include "ia/Tools/Tools.hpp"

// ******** CONSTRUCTEURS ********
Comportement::Comportement() {}
Comportement::Comportement(vector<Noeud *> noeuds) : noeuds(noeuds) {}
Comportement::Comportement(vector<Noeud *> noeuds, Noeud * noeudDepart, Noeud * noeudFin): noeuds(noeuds), noeudDepart(noeudDepart) {
	noeudsFin.push_back(noeudFin);
}
Comportement::Comportement(vector<Noeud *> noeuds, Noeud * noeudDepart, vector<Noeud *>noeudFin) : noeuds(noeuds), noeudDepart(noeudDepart), noeudsFin(noeudFin) {}

// ******** STATIC MEMBERS ********
vector<Comportement *> Comportement::listComportements;

// ******** STATIC METHODS ********
//CETTE FONCTION EST TEMPORAIRE, a faire a partir d'un fichier
int Comportement::initVectorComp(std::string filename) {
	Comportement * c =  new Comportement();

	Noeud * noeudFaimM5 = new Noeud();
	Noeud * noeudFaimP10 = new Noeud();

	Arete * areteFaim20 = new Arete(noeudFaimM5, noeudFaimP10);
	Arete * areteFaim80 = new Arete(noeudFaimP10, noeudFaimM5);

	noeudFaimM5->ajouterAreteOut(areteFaim20);
	noeudFaimM5->ajouterAreteIn(areteFaim80);
	noeudFaimP10->ajouterAreteIn(areteFaim20);
	noeudFaimP10->ajouterAreteOut(areteFaim80);

	ActionSimple * actionFaimM5 = new ActionSimple();
	ActionSimple * actionFaimP10 = new ActionSimple();

	actionFaimM5->setFonc_Void(FONC_FAIM_M5);
	actionFaimP10->setFonc_Void(FONC_FAIM_P10);

	noeudFaimM5->setAction(actionFaimM5);
	noeudFaimP10->setAction(actionFaimP10);

	vector<struct_condition> vecStructCondFaim20;
	struct_condition condFaim20;
	condFaim20.fIE1 = Fonc_GetFaim;
	condFaim20.e1 = nullptr;
	condFaim20.op = Inf;
	condFaim20.comp = 20;
	condFaim20.fIE2 = FONC_I_E_NULL;
	vecStructCondFaim20.push_back(condFaim20);

	areteFaim20->setCondition_Complexe(vecStructCondFaim20);

	vector<struct_condition> vecStructCondFaim80;
	struct_condition condFaim80;
	condFaim80.fIE1 = Fonc_GetFaim;
	condFaim80.e1 = nullptr;
	condFaim80.op = Sup;
	condFaim80.comp = 80;
	condFaim80.fIE2 = FONC_I_E_NULL;
	vecStructCondFaim80.push_back(condFaim80);
	areteFaim80->setCondition_Complexe(vecStructCondFaim80);

	c->ajouterNoeud(noeudFaimM5);
	c->ajouterNoeud(noeudFaimP10);

	c->setNoeudDepart(noeudFaimM5);

	Comportement::addToComportements(c);

	return 1;
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
