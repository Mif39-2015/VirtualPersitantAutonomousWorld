#ifndef ACTION_HPP
#define ACTION_HPP

/*!
 * \file Action.hpp
 * \brief contient la classe Action
 * \author Groupe IA
 */

using namespace std;

#include "Entity/Sentient_Entity.hpp"
#include <stack>
#include <utility>
#include "FonctionEnums.hpp"

// ******** CLASSE ACTION ********

/*!
*\class Action
*\brief Classe abstraite mère des classes ActionComportement et ActionSimple
*/
class Action {
	public :
		/*!
		 	*\brief Execute l'action courante à l'agent passé en paramètre
		 	*\param agent : agent qui éxecute l'action'
		 	*/
		virtual void Executer(Sentient_Entity * agent) {};
};

// ******** CLASSE ACTION COMPORTEMENT********

/*!
*\class ActionComportement
*\brief Classe décrivant les actions contenant un comportement
*/
class ActionComportement : public Action {

	private :

		Comportement * comportement;/*!<comportement composant l'action'*/

	public :
		// ******** CONSTRUCTEUR ********
		ActionComportement() {comportement = nullptr;};
		/*!
		 	*\brief Constructeur avec paramètre
		 	*\param c : comportement qui va composer l'action
		 	*/
		ActionComportement(Comportement * c) : comportement(c) {};

		// ******** GETTERS ********
		Comportement * getComportement() {return comportement;}

		// ******** SETTERS ********
		void setComportement(Comportement * c) {comportement = c;}

		// ******** FONCTIONNEMENT ********
		/*!
		*\brief fait éxecuter le comportement courant un agent
		*\param agent : agent qui éxecute l'action'
		*/
		void Executer(Sentient_Entity * agent);

};

// ******** CLASSE ACTION SIMPLE********

class ActionSimple : public Action {
	private :

		FONC_VOID fV = FONC_V_NULL;
		FONC_VOID_ENTITY fVE = FONC_V_E_NULL;

		stack<FONC_ENTITY_ENTITY> sFEE;
		Entity * parametreFinal;

	public :
		// ******** CONSTRUCTEURS ********
		ActionSimple() {};
		ActionSimple(FONC_VOID foncVoid) : fV(foncVoid) {}
		ActionSimple(FONC_VOID_ENTITY foncVoidEntity, stack<FONC_ENTITY_ENTITY> stack, Entity * e) : fVE(foncVoidEntity), sFEE(stack), parametreFinal(e) {}

		// ******** GETTERS ********
		FONC_VOID getFonc_Void() {return fV;}
		FONC_VOID_ENTITY getFonc_Void_Entity() {return fVE;}
		stack<FONC_ENTITY_ENTITY> getStackFonc_Entity_Entity() {return sFEE;}
		Entity * getParametreFinal() {return parametreFinal;}

		// ******** SETTERS ********
		void setFonc_Void(FONC_VOID foncVoid) {fV = foncVoid;}
		void setFonc_Void_Entity(FONC_VOID_ENTITY foncVoidEntity) {fVE = foncVoidEntity;}
		void setStackFonc_Entity_Entity(stack<FONC_ENTITY_ENTITY> stackFoncEntityEntity) {sFEE = stackFoncEntityEntity;}
		void setParametreFinal(Entity * e) {parametreFinal = e;}

		// ******** AJOUTS ********
		void ajouterFonc_Entity_Entity(FONC_ENTITY_ENTITY foncEntityEntity) {sFEE.push(foncEntityEntity);}

		// ******** FONCTIONNEMENT ********
		void Executer(Sentient_Entity * agent);
};

#endif
