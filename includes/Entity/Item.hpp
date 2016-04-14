#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>
#include "Entity/Entity.hpp"
	
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

#endif
