#ifndef ACTIONCOMPORTEMENT_HPP
#define ACTIONCOMPORTEMENT_HPP

/*!
 * \file ActionComportement.hpp
 * \brief contient la classe ActionComportement
 * \author Groupe IA
 */

using namespace std;

#include "Behavior/Action.hpp"
#include <utility>

class Comportement;

/*!
*\class ActionComportement 
*\brief Classe décrivant les actions contenant un comportement
*/
class ActionComportement : public Action {

	private :
		Comportement * comportement;/*!<comportement composant l'action'*/

	public :
	
		
		/*!
	     	*\brief Constructeur par défaut
	     	*/
		ActionComportement(){comportement = nullptr;};
		
		/*!
	     	*\brief Constructeur avec paramètre
	     	*\param c : comportement qui va composer l'action
	     	*/
		ActionComportement(Comportement * c) : comportement(c) {};

		Comportement * getComportement(){return comportement;}
		void setComportement(Comportement * c){comportement = c;}
		
		/*!
	     	*\brief fait éxecuter le comportement courant un agent
	     	*\param agent : agent qui éxecute l'action'
	     	*/
		void Executer(Sentient_Entity * agent);

};

#endif
