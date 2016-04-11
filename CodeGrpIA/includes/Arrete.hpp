#ifndef ARRETE_HPP
#define ARRETE_HPP

#include "Noeud.hpp"
#include "FunctionCondition.hpp"

using namespace std;

//~ class Noeud;

class Arrete{
	private :

		Noeud * noeudDepart;
		Noeud * noeudFin;

		vector<Fonction_Bool> conditions;

	public :
		/*
		 * nD --> Noeud de départ de l'arrête
		 * nF --> Noeud de fin de l'arrête
		 * f --> pointeur sur fonction de la fonction à executer pour savoir si la condition est vraie ou non
		 * */
		Arrete(Noeud * nD, Noeud * nF) : noeudDepart(nD) , noeudFin(nF) {};
		Arrete(Noeud * nD, Noeud * nF, vector<Fonction_Bool> fC);

		void setNoeudDepart(Noeud * nD);
		void setNoeudFin(Noeud * nF);

		Noeud * getNoeudDepart();
		Noeud * getNoeudFin();

		/*
		 * Utilisé pour savoir si la condition est vérifiée ou non
		 * */
		bool isTrue();

};
#endif
