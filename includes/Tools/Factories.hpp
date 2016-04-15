#ifndef FACTORIES_HPP
#define FACTORIES_HPP

/*!
 * \file Factories.hpp
 * \brief contient la classe Factories
 * \author Groupe IA
 */

#include <fstream>
#include <iostream>
#include "Entity/Characteristics.hpp"
#include "Entity/Sentient_Entity.hpp"
#include "Entity/Tribe.hpp"
#include "Entity/Item.hpp"
#include "Tools/Tools.hpp"

/*! \class Factories 
   * \brief Classe contenant les outils permettant d'instancier les différentes entités
   */
class Factories{

public:
	/*!
     	*  \brief Factory permettant d'instancier les Agents
     	*/
	static Sentient_Entity * createAgent();
	
	/*!
     	*  \brief Factory permettant d'instancier les Animaux
     	*/
	static Sentient_Entity * createAnimal();
	
	/*!
     	*  \brief Factory permettant d'instancier les Items
     	*/
	static Item * createItem();
	
	/*!
     	*  \brief Factory permettant d'instancier les Clans
     	*/
	static Tribe * createTribe();

};

#endif
