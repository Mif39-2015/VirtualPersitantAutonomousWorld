#ifndef ITEM_HPP
#define ITEM_HPP

/*!
 * \file Item.hpp
 * \brief contient les classes Item et ItemList
 * \author Groupe IA
 */


#include <string>
#include <fstream>
#include <vector>
#include "ia/Entity/Entity.hpp"
#include "ia/Tools/Tools.hpp"
#include "tool/cJSON.hpp"


/*! \class Item
* \brief Classe contenant les methodes et les attributs pour gérér les articles dans le tribu
*/

class Item : public Entity {

public:

	static std::vector<Item> listItems; /*!< liste des items provenant du fichier*/

	/*!
	*  \brief Fonction qui construit un vector d'items à partir du fichier donné
	*  \param fileName: le fichier
	*/
	static int loadItemsFile(std::string fileName);

	/*!
	*  \brief Constructeur pour la classe Item
	*/
	Item(std::string, type, std::map<int, int> charac);

	/*!
	*  \brief Fonction pour l'operateur ==
	*  return bool
	*/
	inline bool operator == (const Item &b) const
	{
		return ( id == b.id && name == b.name);
	}

	/*!
	*  \brief Fonction pour l'operateur <
	*  return bool
	*/
	inline bool operator< (const Item &a) const
	{
		return id < a.id;
	}

	/*!
	* \brief Fonction qui renvoie un Item de listItem selon un nom
	* \param n: Le nom de l'Item rechercher
	* Retourne l'Item correspondant
	*/
	static Item * getItemByName(std::string n);

	void updateItem(unsigned int wstime);

	/*!
	*  \brief Destructeur pour la classe Item
	*  return bool
	*/
	~Item();

private:

};

#endif
