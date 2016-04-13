#ifndef ARETE_HPP
#define ARETE_HPP

#include <vector>
#include <stack>

#include "Behavior/Noeud.hpp"
#include "FonctionEnums.hpp"

class Noeud;

using namespace std;

class Arete{
	typedef enum {
		Inf
		,Inf_Eg
		,Eg
		,Sup_Eg
		,Sup
		,OP_NULL
	} Operator;

	struct struct_condition{
		FONC_INT_ENTITY fIE1;
		stack<FONC_ENTITY_ENTITY> fEE1;
		Entity * e1;
		Operator op;
		FONC_INT_ENTITY fIE2;
		stack<FONC_ENTITY_ENTITY> fEE2;
		Entity * e2;
		int comp;
	};

	private :

		Noeud * noeudDepart;
		Noeud * noeudFin;

		vector<FONC_BOOL> conditions_Simples;
		vector<struct_condition> condition_Complexes;

	public :
		/*
		 * nD --> Noeud de départ de l'arrête
		 * nF --> Noeud de fin de l'arrête
		 * f --> pointeur sur fonction de la fonction à executer pour savoir si la condition est vraie ou non
		 * */
		Arete(Noeud * nD, Noeud * nF) : noeudDepart(nD) , noeudFin(nF) {};
		Arete(Noeud * nD, Noeud * nF, vector<FONC_BOOL> fC);

		void setNoeudDepart(Noeud * nD);
		void setNoeudFin(Noeud * nF);

		Noeud * getNoeudDepart();
		Noeud * getNoeudFin();

		/*
		 * Utilisé pour savoir si la condition est vérifiée ou non
		 * */
		bool isTrue(Sentient_Entity * a);

};
#endif
