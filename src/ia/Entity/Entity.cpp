#include <iostream>
#include <cstdlib>
#include <string>
#include "ia/Entity/Entity.hpp"
#include "ia/Entity/Characteristics.hpp"

unsigned int Entity::idCount = 0;

Entity::Entity(std::string n, type tid, std::map<int, int> charac) : typeId(tid), name(n), charact_correspondence(charac), modif(false), idle(true) {
	id = idCount;
	idCount++;
}

unsigned int Entity::getId() {
	return id;
}

std::string Entity::getName() {
	return name;
}

void Entity::setName(std::string n) {
	name = n;
}

type Entity::getTypeId() {
	return typeId;
}

bool Entity::getModif() {
	return modif;
}

bool Entity::getIdle() {
	return idle;
}

void Entity::setModif(bool m) {
	modif = m;
}

void Entity::setIdle(bool i) {
	idle = i;
}

int Entity::getVal(int id) {
	if (charact_correspondence.find(id) == charact_correspondence.end()) {
		return -1;
	}
	return charact_correspondence.at(id);
}

int Entity::setVal(int id, int v) {
	//si la clé n'existe pas on fait rien
	if (getVal(id) == -1) {
		return -1;
	}
	//sinon on met à jour la valeur de la clé existante
	if (v <= Characteristics::listCharacteristics[id].getMax() && v >= Characteristics::listCharacteristics[id].getMin()) {
		charact_correspondence.at(id) = v;
		modif = true;
		return 1;
	}
	if (v > Characteristics::listCharacteristics[id].getMax()) {
		charact_correspondence.at(id) = Characteristics::listCharacteristics[id].getMax();
		modif = true;
		return -2;
	}
	else {
		charact_correspondence.at(id) = Characteristics::listCharacteristics[id].getMin();
		modif = true;
		return -3;
	}
}

void Entity::decade(unsigned int wstime) {
	if (wstime % getVal(C_SATIETY_DECADE) == 0) {
		int sat_dec_val = getVal(C_SATIETY_DECADE_VALUE);
		if (sat_dec_val != -1) {
			setVal(C_SATIETY, getVal(C_SATIETY) - sat_dec_val);
		}
	}
	//Si l'agent ne fait rien
	if (idle) {
		if (wstime % getVal(C_STAMINA_DECADE) == 0) {
			int sta_dec_val = getVal(C_STAMINA_DECADE_VALUE);
			if (sta_dec_val != -1) {
				setVal(C_STAMINA, getVal(C_STAMINA) + (sta_dec_val * 4));
			}
		}
	}
	//Sinon
	else {
		if (wstime % getVal(C_STAMINA_DECADE) == 0) {
			int sta_dec_val = getVal(C_STAMINA_DECADE_VALUE);
			if (sta_dec_val != -1) {
				setVal(C_STAMINA, getVal(C_STAMINA) - sta_dec_val);
			}
		}
	}
}

cJSON* Entity::toJson() {

	cJSON *root;
	root = cJSON_CreateObject();
	cJSON_AddNumberToObject(root, "id", this->id);
	cJSON_AddStringToObject(root, "typeId", TypeNames[this->typeId]);
	cJSON_AddStringToObject(root, "name", this->name.c_str());
	
	//ajout des caractéristiques
	cJSON * characs;
	characs = cJSON_CreateArray();

	for(auto it = charact_correspondence.begin(); it != charact_correspondence.end(); it++){
		string charID = std::to_string(it->first);
		cJSON* charac = cJSON_CreateObject();
		cJSON_AddNumberToObject(charac, charID.c_str(),it->second);
		cJSON_AddItemToArray(characs, charac);
	}
	
	cJSON_AddItemToObject(root,"characteristics", characs);

	return root;
}


unsigned int Entity::isHungry(void) {
	int s = getVal(C_SATIETY);
	int s_t = getVal(C_SATIETY_THRESHOLD);
	if (s >= 0 && s_t >= 0) {
		if (s <= s_t) return 1;
		else if (s > s_t) return 0;
	}
	return -1;
}

unsigned int Entity::isTired(void) {
	int s = getVal(C_STAMINA);
	int s_t = getVal(C_STAMINA_THRESHOLD);
	if (s >= 0 && s_t >= 0) {
		if (s <= s_t) return 1;
		else if (s > s_t) return 0;
	}
	return -1;
}

void Entity::affiche()
{}

Entity::~Entity(void) {}
