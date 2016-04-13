#ifndef COMPORTEMENT_HPP
#define COMPORTEMENT_HPP

using namespace std;

#include <vector>
#include "Behavior/Noeud.hpp"

class Noeud;

class Comportement {
	/*
	 * Attention ! bien que l'on passe des pointeurs sur un Noeud, un même Noeud ne peux pas faire partie de plusieurs comportement différents.
	 * */
	private :
		vector<Noeud *> noeuds;
		Noeud * noeudDepart;
		vector<Noeud *> noeudsFin;

	public :
		/*
		 * Constructeur par défault de la classe, initialise noeudDepart et noeudFin à NULL
		 * */
		Comportement();
		/*
		 * vN --> vector (rempli) contenant les noeuds du comportement
		 * nD --> noeud de départ du comportement
		 * nF --> noeud de fin du comportement
		 * */
		Comportement(vector<Noeud*> vN, Noeud * nD, vector<Noeud*> nFs);
		/*
		 * Ajoute le Noeud n aux noeuds du comportement
		 * */
		void ajouterNoeud(Noeud * n);
		/*
		 * Supprime le Noeud n du comportement et supprime les arrêtes liées à n
		 * */
		void supprimerNoeud(Noeud * n);

		void setNoeudDepart(Noeud * nD);
		void setNoeudFin(vector<Noeud *> nFs);

		Noeud * getNoeudDepart();
		vector<Noeud *> getNoeudFin();
};
#endif
