#ifndef ITEM_HPP
#define ITEM_HPP

/*!
 * \file Item.hpp
 * \brief Fichier contenant la classe Item
 * \author Groupe IA
 */

#include <string>

/*! 
* \class Item
* \brief classe permettant de représenter les items
*/
class Item {    
public:
	Item(unsigned int, std::string, float);

	const unsigned int& getID();

	const std::string& getName();

	const float& getWeight();

	//pas de set, les valeurs ne seront pas forcément modifiables

	inline bool operator == (const Item &b) const
    {
        return ( id == b.id && name == b.name);
    }

    inline bool operator< (const Item &a) const
    {
        return id < a.id;
    }

	~Item(void);

private:
	unsigned int id;
	std::string name;
	float weight;

};

#endif
