#include "ia/Behavior/Arete.hpp"

// ******** CONSTRUCTEURS ********
Arete::Arete() {
	noeudDepart = nullptr;
	noeudFin = nullptr;
}
Arete::Arete(Noeud * nD, Noeud * nF) : noeudDepart(nD) , noeudFin(nF) {
	noeudDepart->ajouterAreteOut(this);
	noeudFin->ajouterAreteIn(this);
}

// ******** GETTERS ********
Noeud * Arete::getNoeudDepart() {
	return noeudDepart;
}
Noeud * Arete::getNoeudFin() {
	return noeudFin;
}
vector<FONC_BOOL> Arete::getConditon_Simple() {
	return condition_simple;
}
vector<struct_condition> Arete::getCondition_Complexe() {
	return condition_Complexe;
}

// ******** SETTERS ********
void Arete::setNoeudDepart(Noeud * nD) {
	noeudDepart = nD;
}
void Arete::setNoeudFin(Noeud * nF) {
	noeudFin = nF;
}
void Arete::setCondition_Simple(vector<FONC_BOOL> conds) {
	condition_simple = conds;
}
void Arete::setCondition_Complexe(vector<struct_condition> conds) {
	condition_Complexe = conds;
}

// ******** FONCTIONNEMENT ********
bool Arete::isTrue(Sentient_Entity * a) {
	for (auto it = condition_simple.begin(); it != condition_simple.end(); ++it) {
		if (!MapEnumPointeur::mapFoncBool[*it](a)) return false;
	}

	for (auto it = condition_Complexe.begin(); it != condition_Complexe.end(); ++it) {
		// Entity * e = it->e1;
		Entity * e = nullptr;
		stack<FONC_ENTITY_ENTITY> stackFEE(it->fEE1);
		while (!it->fEE1.empty()) {
			e = MapEnumPointeur::mapFoncEntityEntity[stackFEE.top()](a, e);
			stackFEE.pop();
		}

		int val1 = MapEnumPointeur::mapFoncIntEntity[it->fIE1](a, e);
		cout << "la val1 est : " << val1 << endl;

		int val2;
		if (it->fIE2 != FONC_I_E_NULL) {
			stack<FONC_ENTITY_ENTITY> stackFEE2(it->fEE2);
			// e = it->e2;
			e = nullptr;
			while (!stackFEE2.empty()) {
				e = MapEnumPointeur::mapFoncEntityEntity[stackFEE2.top()](a, e);
				stackFEE2.pop();
			}
			val2 = MapEnumPointeur::mapFoncIntEntity[it->fIE2](a, e);
		}
		else {
			val2 = it->comp;
		}
		cout << "la val2 est : " << val2 << endl;
		switch (it->op) {
		case Inf :
			if (!(val1 < val2)) return false;
			break;
		case Inf_Eg :
			if (!(val1 <= val2)) return false;
			break;
		case Eg :
			if (!(val1 == val2)) return false;
			break;
		case Sup_Eg :
			if (!(val1 >= val2)) return false;
			break;
		case Sup :
			if (!(val1 > val2)) return false;
			break;
		default :
			break;
		}
	}

	return true;
}
