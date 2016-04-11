#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <string>
#include <map>

#include "Position.hpp"
#include "Item.hpp"


class Entity{

public:
	std::map<Item, unsigned int> inventory;
	Position pos;

	Entity(std::string);

        unsigned int getId();
        std::string getName();
        Position getPos();
        std::map<Item, unsigned int> getInventory();
        void setName(std::string n);
        void setPos(int x, int y);
        void setInventory(std::map<Item, unsigned int> inv);
	~Entity(void);

protected:
        static unsigned int idCount;
	unsigned int id;
	std::string name;
};

#endif
