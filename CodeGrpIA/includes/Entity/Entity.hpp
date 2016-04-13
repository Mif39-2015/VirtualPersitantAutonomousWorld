#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <string>
#include <map>

#include "Tools/Position.hpp"
#include "Item.hpp"

// using namespace std;
enum type{
    ID_AGENT,
    ID_ANIMAL,
    ID_BUILDING,
    ID_RESSOURCE
};

class Entity{

	protected:

		static unsigned int idCount;
		unsigned int id;
		// type typeId;
		int typeId;
		std::string name;
		std::map<Item, unsigned int> inventory;
		Position pos;
		bool modif;

	public:

        Entity(std::string, int);

		unsigned int getId();
		std::string getName();
		Position getPos();
		bool getModif();
		std::map<Item, unsigned int> getInventory();
		int getTypeId();
		void setModif(bool m);
		void setName(std::string n);
		void setPos(int x, int y);
		void setInventory(std::map<Item, unsigned int> inv);

		~Entity(void);
};

#endif
