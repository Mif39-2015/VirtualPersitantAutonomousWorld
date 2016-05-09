#include <iostream>
#include "ia/Entity/Insentient_Entity.hpp"

Insentient_Entity::Insentient_Entity(std::string n, type tid, std::map<int, int> charac, int x, int y) : Tangible_Entity(n, tid, charac, Position(x, y)) {}

void Insentient_Entity::updateResource(unsigned int wstime) {
	if (typeId == ID_RESSOURCE) {
		if (this->getVal(C_RESPAWN_RATE) != 0 && (wstime % this->getVal(C_RESPAWN_RATE)) == 0) {
			Characteristics * c = Characteristics::getCharacById(Characs::C_MAXRESSTOCK);
			for (auto it = stock.begin(); it != stock.end(); it++) {
				if (it->second < c->getMax()) {
					it->second = it->second + this->getVal(C_RESPAWN_VALUE);
				}
				if (it->second >= c->getMax()) {
					it->second = c->getMax();
				}
			}
		}
	}
}

void Insentient_Entity::affiche(){}

cJSON* Insentient_Entity::toJson(){
		cJSON * tangible_entity = Tangible_Entity::toJson();
		return tangible_entity;
}
