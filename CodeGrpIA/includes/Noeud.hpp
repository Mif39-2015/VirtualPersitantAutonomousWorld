#ifndef NOEUD_HPP
#define NOEUD_HPP

#include <vector>
//~ #include "Include.hpp"
#include "Action.hpp"
#include "Arrete.hpp"
#include "Sentient_Entity.hpp"

using namespace std;

class Arrete;

class Noeud {
	private :
		vector<Arrete *> arretesOut;
		vector<Arrete *> arretesIn;
		Action * action;

	public :
		/*
		 * a -> l'action du noeud
		 * vAO -> le vecteur(rempli) d'arrêtes partant de ce noeud
		 * vAI -> le vecteur(rempli) d'arrêtes allant à ce noeud
		 * */
		Noeud();
		Noeud(Action * a);
                Noeud(Noeud * n);

		void setAction(Action * a);
		Action * getAction();

		/*
		* cette fonction est la fonction primaire du Noeud, elle est à appeller quand l'agent est activement sur ce Noeud.
		* Elle executera d'elle-même l'Action à executer ou renvera le Noeud sur lequel l'agent se trouve si une condition d'une des arrête se trouve être remplie
		* Si l'agent ne doit pas changer de Noeud, le Noeud renvoie un pointeur sur lui-même
		* //TODO :
		* 	- checker les condition des arrêtes
		* 	- si une arrête a une condition valide, on execute le Noeud suivant ( = executerNoeud du noeud de l'autre côté de l'arrête)
		* 	- sinon, on execute l'action de action
		* */
		Noeud * executerNoeud(Sentient_Entity * a);
};
#endif
