#ifndef ARETE_HPP
#define ARETE_HPP

#include "Noeud.hpp"
#include "FonctionCondition.hpp"

using namespace std;

class Noeud;

class Arete{
	private :

		Noeud * noeudDepart;
		Noeud * noeudFin;

		vector<Fonction_Bool> conditions_Simples;
		vector<struct_condition> condition_Complexes;

	public :
		/*
		 * nD --> Noeud de départ de l'arrête
		 * nF --> Noeud de fin de l'arrête
		 * f --> pointeur sur fonction de la fonction à executer pour savoir si la condition est vraie ou non
		 * */
		Arete(Noeud * nD, Noeud * nF) : noeudDepart(nD) , noeudFin(nF) {};
		Arete(Noeud * nD, Noeud * nF, vector<Fonction_Bool> fC);

		void setNoeudDepart(Noeud * nD);
		void setNoeudFin(Noeud * nF);

		Noeud * getNoeudDepart();
		Noeud * getNoeudFin();

		/*
		 * Utilisé pour savoir si la condition est vérifiée ou non
		 * */
		bool isTrue(Sentient_Entity * a);
			//~ int val1 = map.find(condition_Complexes[i].fonc)(a,condition_Complexes[i].e1));
			//~ if(condition_Complexes[i].fonc2!=FONC_NULL)
				//~ int val2 = map.find(condition_Complexes[i].fonc2)(a,condition_Complexes[i].e2));
			//~ else int val2 = condition_Complexes[i].comp;
			//~ switch(condition_Complexes[i].op){
				//~ case Inf :
					//~ return val1 < val2;
					//~ case Inf_Eg
					//~ return val1 <= val2;
			//~ }

};
#endif
