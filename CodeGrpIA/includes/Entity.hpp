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

	~Entity(void);

private:
	unsigned int id;
	std::string name;
};

#endif
