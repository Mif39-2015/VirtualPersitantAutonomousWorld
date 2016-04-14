#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>
#include "Entity/Entity.hpp"
	
class Item : public Entity {    
public:
	Item(unsigned int, std::string, float, type);

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
