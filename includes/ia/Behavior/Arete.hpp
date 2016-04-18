#ifndef ARETE_HPP
#define ARETE_HPP

#include <vector>
#include <stack>

#include "ia/Behavior/Noeud.hpp"
#include "ia/Behavior/FonctionEnums.hpp"

class Noeud;

using namespace std;

typedef enum {
	Inf
	, Inf_Eg
	, Eg
	, Sup_Eg
	, Sup
	, OP_NULL
} Operator;

struct struct_condition {
	FONC_INT_ENTITY fIE1;
	stack<FONC_ENTITY_ENTITY> fEE1;
	Entity * e1;
	Operator op;
	FONC_INT_ENTITY fIE2;
	stack<FONC_ENTITY_ENTITY> fEE2;
	Entity * e2;
	int comp;
};

class Arete {

	private :
		Noeud * noeudDepart;
		Noeud * noeudFin;

		vector<FONC_BOOL> condition_simple;
		vector<struct_condition> condition_Complexe;

	public :
		// ******** CONSTRUCTEURS ********
		Arete();
		Arete(Noeud * nD, Noeud * nF);

		// ******** DESTRUCTEURS ********
		~Arete();

		// ******** GETTERS ********
		Noeud * getNoeudDepart();
		Noeud * getNoeudFin();
		vector<FONC_BOOL> getConditon_Simple();
		vector<struct_condition> getCondition_Complexe();

		// ******** SETTERS ********
		void setNoeudDepart(Noeud * nD);
		void setNoeudFin(Noeud * nF);
		void setCondition_Simple(vector<FONC_BOOL> conds);
		void setCondition_Complexe(vector<struct_condition> conds);

		// ******** FONCTIONNEMENT ********
		/*
		 * Utilisé pour savoir si la condition est vérifiée ou non
		 * */
		bool isTrue(Sentient_Entity * a);
};

#endif
