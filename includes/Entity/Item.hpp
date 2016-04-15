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
#include "Entity/Entity.hpp"
#include "Tools/Tools.hpp"
#include "../src/tool/cJSON.hpp"


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
		Item(std::string, type,std::map<int, int> charac);

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
		*  \brief Destructeur pour la classe Item
		*  return bool
		*/
		~Item();

	private:

};

/*! \class ItemList
*   \brief Classe contenant les methodes et les attributs pour gérér les items dans un fichier
*/

// class ItemList{

// 	public:

// 		static std::vector<Item> listItems; /*!< liste des items provenant du fichier*/

 		/*!
 		*  \brief Fonction qui construit un vector d'items à partir du fichier donné
 		*  \param fileName: le fichier
		*/
// 		static int loadItemsFile(std::string fileName);

// };

#endif
