#ifndef ARETE_HPP
#define ARETE_HPP

#include <vector>
#include <stack>

#include "Behavior/Noeud.hpp"
#include "FonctionEnums.hpp"

class Noeud;

using namespace std;

class Arete{
	public :
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

		vector<FONC_BOOL> condition_simple;
		vector<struct_condition> condition_Complexe;

	public :
		/*
		 * nD --> Noeud de départ de l'arrête
		 * nF --> Noeud de fin de l'arrête
		 * f --> pointeur sur fonction de la fonction à executer pour savoir si la condition est vraie ou non
		 * */
		Arete(Noeud * nD, Noeud * nF) : noeudDepart(nD) , noeudFin(nF) {};

		Noeud * getNoeudDepart(){return noeudDepart;}
		Noeud * getNoeudFin(){return noeudFin;}
		vector<FONC_BOOL> getConditon_Simple(){return condition_simple;}
		vector<struct_condition> getCondition_Complexe(){return condition_Complexe;}

		void setNoeudDepart(Noeud * nD){noeudDepart=nD;};
		void setNoeudFin(Noeud * nF){noeudFin=nF;}

		/*
		 * Utilisé pour savoir si la condition est vérifiée ou non
		 * */
		bool isTrue(Sentient_Entity * a);

};
#endif
