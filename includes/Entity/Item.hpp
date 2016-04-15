#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>
#include <fstream>
#include <vector>
#include "Entity/Entity.hpp"
#include "Tools/Tools.hpp"
	
class Item : public Entity {    
public:

	Item(std::string, type,std::map<int, int> charac);

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
	
};


class ItemList{

public:
    //les items provenant du fichier
	static std::vector<Item> listItems;

	//construit un vector d'items à partir du fichier donné
	static int loadItemsFile(std::string fileName);

};
#endif
