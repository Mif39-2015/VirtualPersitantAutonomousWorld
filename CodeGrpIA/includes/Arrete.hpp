#ifndef ARRETE_HPP
#define ARRETE_HPP

//~ #include "Include.hpp"
#include "Noeud.hpp"

using namespace std;

class Noeud;

class Arrete{
	private :
		Noeud * noeudDepart;
		Noeud * noeudFin;

		bool (*condition);

	public :
		/*
		 * nD --> Noeud de départ de l'arrête
		 * nF --> Noeud de fin de l'arrête
		 * f --> pointeur sur fonction de la fonction à executer pour savoir si la condition est vraie ou non
		 * */
		Arrete(Noeud * nD, Noeud * nF);
		Arrete(Noeud * nD, Noeud * nF, bool (*f));

		void setNoeudDepart(Noeud * nD);
		void setNoeudArrivee(Noeud * nF);

		Noeud * getNoeudDepart();
		Noeud * getNoeudArrivee();

		void setCondition(bool(*f));
		//bool(*function) getCondition();

		/*
		 * Utilisé pour savoir si la condition est vérifiée ou non
		 * */
		bool isTrue();

};
#endif
