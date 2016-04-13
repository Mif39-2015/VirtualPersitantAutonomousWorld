#ifndef ENTITY_HPP
#define ENTITY_HPP

/*!
 * \file Entity.hpp
 * \brief Fichier contenant la classe Entity
 * \author Groupe IA
 */

#include <string>
#include <map>

#include "Tools/Position.hpp"
#include "Item.hpp"

using namespace std;
/*! 
* \class Entity
* \brief classe permettant de représenter les différentes entités (Agent, Animal, Ressource, ...)
*/
class Entity{

	public:

		/*!
		 *\brief Constructeur
	 	 *\param n : le nom de l'entité
	 	 *\param tid : le type de l'ent'
	 	 */
		Entity(std::string n, std::string tid);

		//Getters
		unsigned int getId();
		string getName();
		Position getPos();
		bool getModif();
		map<Item, unsigned int> getInventory();
		
		//Setters
		string getTypeId();
		void setModif(bool m);
		void setName(std::string n);
		void setPos(int x, int y);
		void setInventory(std::map<Item, unsigned int> inv);

		/*!
		*\brief Destructeur
		*/
		~Entity(void);

	protected:
		static unsigned int idCount; /*!<Compteur d'entités permettant de générer l'identifiant*/
		unsigned int id; /*!<Identifiant unique de l'entité*/
		string typeId; /*!<Identifiant du type de l'entité (Agent, Animal, Resource, ...)'*/
		string name; /*!<Nom de l'entité*/
		map<Item, unsigned int> inventory; /*!<Inventaire de l'entité*/
		Position pos; /*!<Position de l'entité*/
		bool modif; /*!<Booléen indiquant si l'entité a été modifiée depis le dernier transfert de données*/

	
};

#endif
