#ifndef COMPORTEMENT_HPP
#define COMPORTEMENT_HPP

using namespace std;

#include <vector>
#include "ia/Behavior/Noeud.hpp"

class Noeud;

class Comportement
{

	private :

		vector<Noeud *> noeuds;
		Noeud * noeudDepart;
		vector<Noeud *> noeudsFin;

		string nom;

	public :

		// ******** STATICS CONTAINERS ********
		static vector<Comportement *> listComportements;
		static void addToComportements(Comportement * c) {listComportements.push_back(c);}

		// ******** STATICS METHODS ********
		static int initVectorComp(std::string filename);

		// ******** CONSTRUCTEUR ********
		Comportement();
		Comportement(vector<Noeud *> noeuds);
		Comportement(vector<Noeud *> noeuds, Noeud * noeudDepart, Noeud * noeudFin);
		Comportement(vector<Noeud *> noeuds, Noeud * noeudDepart, vector<Noeud *> noeudFin);
		Comportement(Comportement * c);

		// ******** GETTERS ********
		vector<Noeud *> getNoeuds();
		Noeud * getNoeudDepart();
		vector<Noeud *> getNoeudFin();

		// ******** SETTERS ********
		void setNoeuds(vector<Noeud *> noeuds);
		void setNoeudDepart(Noeud * noeud);
		void setNoeudFin(vector<Noeud *> noeudFin);

		// ******** AJOUTS ********
		void ajouterNoeud(Noeud * n);
		/*!
			\brief Ajoute le Noeud * n au vector des noeuds de fin du comportement et au vector des noeuds s'il n'en faisait pas déjà partie
		*/
		void ajouterNoeudFin(Noeud * n);

		// ******** SUPPRESSION ********
		void supprimerNoeud(Noeud * n);
		void supprimerNoeudFin(Noeud * n);
};
#endif
