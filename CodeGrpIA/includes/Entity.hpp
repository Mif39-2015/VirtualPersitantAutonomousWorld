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

	Entity(unsigned int, std::string);

        int getId();
        std::string getName();
        Position getPos();
        std::map<Item, unsigned int> getInventory();
        void setId(int i);
        void setName(std::string n);
        void setPos(int x, int y);
        void setInventory(std::map<Item, unsigned int> inv);
	~Entity(void);

private:
	unsigned int id;
	std::string name;
};

#endif
