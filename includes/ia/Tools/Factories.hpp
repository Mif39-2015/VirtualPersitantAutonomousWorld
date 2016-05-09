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

enum ResourceType {
	T_BOIS,/*!< Signifie que la ressource contient du bois*/
	T_PIERRE,/*!< Signifie que la ressource contient de la pierre*/
	T_METAL,/*!< Signifie que la ressource contient du metal*/
	T_LEGUME,/*!< Signifie que la ressource contient des légumes*/
	T_VIANDE/*!< Signifie que la ressource contient de la viande*/
};

enum BuildingType {
	B_CITYHALL /*!< Signifie que le batiment est la mairie (City Hall)*/
};

/*!
*\class Factories
*\brief Classe contenant les outils permettant d'instancier les différentes entités
*/
class Factories {

public:
	/*!
 	*\brief Factory permettant d'instancier les Agents
 	*\return Un nouvel Agent
 	*/
	static Sentient_Entity * createAgent();

	/*!
 	*\brief Factory permettant d'instancier les Animaux
 	*\return Un nouvel Animal
 	*/
	static Sentient_Entity * createAnimal();

	/*!
 	*\brief Factory permettant d'instancier les Clans
 	*\return Un nouveau Clan (Tribu)
 	*/
	static Tribe * createTribe();

	/*!
 	* \brief Factory permettant d'instancier les Ressources
 	* \param type: Type de la ressource à créer
 	* \return Une nouvelle Ressource
 	*/
	static Insentient_Entity * createResource(ResourceType type);

	/*!
 	* \brief Factory permettant d'instancier les Buildings
 	* \param bt: Type du batiment à créer
 	* \return Un nouveau Building
 	*/
	static Insentient_Entity * createBuilding(BuildingType bt);

};

#endif
