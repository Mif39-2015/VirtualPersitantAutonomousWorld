#ifndef SENTIENT_ENTITY_HPP
#define SENTIENT_ENTITY_HPP

#include <string>
#include <map>

#include "Entity.hpp"
//#include "Characteristic.hpp"

class Sentient_Entity : public Entity{

	protected:
		//idc int c'est l'id de la caractéristique et val 2eme est l'id de ce cen
		std::map<int, int> charact_correspondence;

	public:
		Sentient_Entity(int, int, std::string, std::string);

		int getVal(int id);
		int setVal(int id, int v);

		int getPosX();
		int getPosY();

		void setPosX(int _x);
		void setPosY(int _y);

};

#endif
