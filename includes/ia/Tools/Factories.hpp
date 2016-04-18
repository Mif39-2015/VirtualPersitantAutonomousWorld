#ifndef FACTORIES_HPP
#define FACTORIES_HPP

/*!
 * \file Factories.hpp
 * \brief contient la classe Factories
 * \author Groupe IA
 */

#include <fstream>
#include <iostream>
#include "ia/Entity/Characteristics.hpp"
#include "ia/Entity/Sentient_Entity.hpp"
#include "ia/Entity/Insentient_Entity.hpp"
#include "ia/Entity/Tribe.hpp"
#include "ia/Entity/Item.hpp"
#include "ia/Tools/Tools.hpp"

/*!
*\class Factories
*\brief Classe contenant les outils permettant d'instancier les différentes entités
*/
class Factories{

public:
	/*!
     	*\brief Factory permettant d'instancier les Agents
     	*/
	static Sentient_Entity * createAgent();

	/*!
     	*\brief Factory permettant d'instancier les Animaux
     	*/
	static Sentient_Entity * createAnimal();

	/*!
     	*\brief Factory permettant d'instancier les Items
     	*/
	static Item * createItem();

	/*!
     	*\brief Factory permettant d'instancier les Clans
     	*/
	static Tribe * createTribe();
	
	/*!
     	*\brief Factory permettant d'instancier les Ressources
     	*/
	static Insentient_Entity * createResource();
	
	/*!
     	*\brief Factory permettant d'instancier les Buildings
     	*/
	static Insentient_Entity * createBuilding();

};

#endif
