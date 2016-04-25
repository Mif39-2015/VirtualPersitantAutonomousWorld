#ifndef TANGIBLE_ENTITY_HPP
#define TANGIBLE_ENTITY_HPP
/*!
* \file Tangible_Entity.hpp
* \brief contient la classe Tangible_Entity
* \author Groupe IA
*/

#include "ia/Tools/Position.hpp"
#include "ia/Entity/Entity.hpp"
#include "ia/Entity/Item.hpp"

using namespace std;
/*!
* \class Tangible_Entity
* \brief Classe héritant de la classe Entity et contenant les attributs et methodes nécessaires pour la gestion des entités tangibles
*/
class Tangible_Entity : public Entity {

public:

	/*!
	* \brief Le constructeur de l'instanciation de l'entité tangible
	*/
	Tangible_Entity(std::string, type, std::map<int, int> charac, Position);

	/*!
	* \brief Renvoie la position de l'entité
	*/
	Position getPos();

	/*!
	* \brief Met à jour la position de l'entité
	* \param x: la position x
	* \param y: la position y
	*/
	void setPos(int x, int y);

	/*!
	*  \brief Fonction d'accesseur qui renvoie la valeur de la quantité pour un article
	*  \param i: l'id d'un article
	*  \return integer
	*/
	int getQuantityByItem(Item* i);

	/*!
	*  \brief Ajoute un article avec sa quantité dans le stock
    *  \param i: l'id de l'article
    *  \param quantity: la quantité de l'article
	*/
	void addItemToStock(Item* i, int quantity);

	/*!
	* \brief Enlève une certaine quantité d'un objet du stock
	* \param i: L'item à enlever
	* \param quantity: la quantité à enlever
	*/
	void removeItemFromStock(Item * i, int quantity);

	/*!
    *  \brief Affiche la liste de stock
    */
	void afficheStock();
	
	void affiche();
	
	/*!
	* \brief conversion de l'objet en objet CJson
	*/
	cJSON* toJson();

protected:

	Position pos; /*!< la position de l'entité*/
	std::map<Item*, int> stock; /*!< Conteneur qui associe la valeur de la quantité à chaque article du stock*/


};
#endif /* TANGIBLE_ENTITY_HPP */

