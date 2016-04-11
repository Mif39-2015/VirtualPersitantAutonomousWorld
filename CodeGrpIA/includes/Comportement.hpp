#ifndef COMPORTEMENT_HPP
#define COMPORTEMENT_HPP

//~ #include "Include.hpp"
#include "Noeud.hpp"
#include <vector>

using namespace std;

class Comportement {
	/*
	 * Attention ! bien que l'on passe des pointeurs sur un Noeud, un Noeud ne peux pas faire partie de plusieurs comportement différents.
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
		void AjouterNoeud(Noeud * n);
		/*
		 * Supprime le Noeud n du comportement et supprime les arrêtes liées à n
		 * */
		void SupprimerNoeud(Noeud * n);

};
#endif
