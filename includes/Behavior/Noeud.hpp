#ifndef NOEUD_HPP
#define NOEUD_HPP

using namespace std;

#include <vector>
#include "Behavior/Arete.hpp"
#include "Behavior/Action.hpp"

class Action;
class Arete;

class Noeud {

	private :

		vector<Arete *> aretesOut;
		vector<Arete *> aretesIn;
		Action * action;

	public :

		// ******** CONSTRUCTEURS ********
		Noeud();
		Noeud(Action * a);

		// ******** DESTRUCTEUR ********
		~Noeud();

		// ******** GETTERS ********
		vector<Arete *> getAretesOut();
		vector<Arete *> getAretesIn();
		Action * getAction();

		// ******** SETTERS ********
		void setAretesOut(vector<Arete *> aretesOut);
		void setAretesIn(vector<Arete *> aretesIn);
		void setAction(Action * a);

		// ******** AJOUTS ********
		void ajouterAreteOut(Arete * a);
		void ajouterAreteIn(Arete * a);

		// ******** SUPPRESSION ********
		void supprimerAreteOut(Arete * a);
		void supprimerAreteIn(Arete * a);

		// ******** FONCTIONNEMENT ********
		/*!
			\brief La fonction principale de fonctionnement d'un Noeud.
			\param a : La Sentient_Entity étant sur le noeud et qui doit donc executer l'action.
			\param execAct : Un booléen indiquant si oui ou non on doit executer l'action contenue dans le noeud au cas où aucune de ses conditions n'est vérifiée
			\return Noeud * pointant sur le prochain Noeud du comportement à executer par la Sentient_Entity. (Notez bien que c'est le Noeud du comportement et ce ne sera pas le Noeud d'un comportmenet contenu dans l'action)

			Cette méthode est le coeur du fonctionnement du Noeud dans le comportement. elle regarde si une des conditions sortante est vérifiée (via les AretesOut).
			Si une arete est vérifiée, la fonction renvoie le Noeud de l'autre côté de l'arete. Sinon, elle execute (ou non) l'action.
		*/
		Noeud * executerNoeud(Sentient_Entity * a, bool execAct = true);
};
#endif
