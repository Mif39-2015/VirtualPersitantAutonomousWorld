#ifndef TANGIBLE_ENTITY_HPP
#define TANGIBLE_ENTITY_HPP

#include "Entity/Entity.hpp"
#include "Tools/Position.hpp"
#include "Entity/Item.hpp"

using namespace std;

class Tangible_Entity : public Entity {

protected:
	Position pos;
	map<Item, unsigned int> inventory;

public:
    Tangible_Entity(std::string, type, Position);
	Position getPos();
	map<Item, unsigned int> getInventory();
	void setPos(int x, int y);
	void setInventory(std::map<Item, unsigned int> inv);
};


#endif /* TANGIBLE_ENTITY_HPP */

