#ifndef ACTION_HPP
#define ACTION_HPP

/*!
 * \file Action.hpp
 * \brief contient la classe Action
 * \author Groupe IA
 */

using namespace std;

#include "Entity/Sentient_Entity.hpp"

/*!
*\class Action 
*\brief Classe abstraite mère des classes ActionComportement et ActionSimple 
*/
class Action {

	public :
		
		/*!
	     	*\brief fait éxecuter le comportement courant un agent
	     	*\param agent : agent qui éxecute l'action'
	     	*/	
		virtual void Executer(Sentient_Entity * agent){};
};

#endif
