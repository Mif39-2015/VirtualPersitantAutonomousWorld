#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <string>
#include <map>

#include "Position.hpp"
#include "Item.hpp"

using namespace std;

class Entity{

protected:
	static unsigned int idCount;
	unsigned int id;
	string typeId;
	string name;
	map<Item, unsigned int> inventory;
	Position pos;

public:

	Entity(std::string, std::string);

	unsigned int getId();
	string getName();
	Position getPos();
	map<Item, unsigned int> getInventory();
    string getTypeId();
	void setName(std::string n);
	void setPos(int x, int y);
	void setInventory(std::map<Item, unsigned int> inv);

	~Entity(void);

};

#endif
