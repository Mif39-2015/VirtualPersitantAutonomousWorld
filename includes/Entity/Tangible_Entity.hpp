#ifndef TANGIBLE_ENTITY_HPP
#define TANGIBLE_ENTITY_HPP
/*!
 * \file Tangible_Entity.hpp
 * \brief contient la classe Tangible_Entity
 * \author Groupe IA
 */
#include "Entity/Entity.hpp"
#include "Tools/Position.hpp"
#include "Entity/Item.hpp"

using namespace std;
/*! \class Tangible_Entity
   * \brief Classe héritant de la classe Entity et contenant les attributs et methodes nécessaires pour la gestion des entités tangibles
   */
class Tangible_Entity : public Entity {

	public:
		/*!
		* \brief Le constructeur de l'instanciation de l'entité tangible
		* */
		Tangible_Entity(std::string, type,std::map<int, int> charac, Position);
		/*!
		* \brief Renvoie la position de l'entité
		* */
		Position getPos();
		/*!
		* \brief Renvoie l'inventaire de l'entité
		* \return l'inventaire
		* */
		map<Item, unsigned int> getInventory();
		/*!
		* \brief Met à jour la position de l'entité
		* \param x: la position x
		* \param y: la position y
		* */
		void setPos(int x, int y);
		/*!
		* \brief Met à jour l'inventaire
		* \param inv: l'inventaire de l'entité
		* */
		void setInventory(std::map<Item, unsigned int> inv);

	protected:
		Position pos; /*!< la position de l'entité*/
		map<Item, unsigned int> inventory;/*!< l'inventaire de l'entité*/


};


#endif /* TANGIBLE_ENTITY_HPP */

