#include <iostream>
#include "ia/Entity/Insentient_Entity.hpp"

Insentient_Entity::Insentient_Entity(std::string n, type tid, std::map<int, int> charac, int x, int y) : Tangible_Entity(n, tid, charac, Position(x, y)) {}

void Insentient_Entity::updateResource(unsigned int wstime) {
	std::cout<<"UPDATE"<<std::endl;
	if (this->getTypeId() == type::ID_RESSOURCE_BOIS
	        || this->getTypeId() == type::ID_RESSOURCE_PIERRE
	        || this->getTypeId() == type::ID_RESSOURCE_METAL
	        || this->getTypeId() == type::ID_RESSOURCE_VIANDE
	        || this->getTypeId() == type::ID_RESSOURCE_LEGUME) {
		if (this->getVal(C_RESPAWN_RATE) != 0 && (wstime % this->getVal(C_RESPAWN_RATE)) == 0) {
			Characteristics * c = Characteristics::getCharacById(Characs::C_MAXRESSTOCK);
			for (auto it = stock.begin(); it != stock.end(); it++) {
				if (it->second < c->getMax()) {
					it->second = it->second + this->getVal(C_RESPAWN_VALUE);
					setModif(true);
				}
				if (it->second >= c->getMax()) {
					it->second = c->getMax();
					setModif(true);
				}
			}
		}
	}
}

void Insentient_Entity::affiche() {
	std::cout << "TODO" << std::endl;
}

cJSON* Insentient_Entity::toJson() {
	cJSON * tangible_entity = Tangible_Entity::toJson();
	return tangible_entity;
}
