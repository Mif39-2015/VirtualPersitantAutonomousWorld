#include <iostream>
#include "ia/Entity/Entity.hpp"

unsigned int Entity::idCount = 0;

Entity::Entity(std::string n, type tid, std::map<int, int> charac) : typeId(tid), name(n), charact_correspondence(charac) {
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

void Entity::setModif(bool m) {
	modif = m;
}

int Entity::getVal(int id) {
	if (charact_correspondence.find(id) == charact_correspondence.end()) {
		return -1;
	}
	return charact_correspondence.at(id);
}

int Entity::setVal(int id, int v) {
	//si la clé n'existe pas on fait rien
	if (charact_correspondence.find(id) == charact_correspondence.end()) {
		return -1;
	}
	//sinon on met à jour la valeur de la clé existante

	charact_correspondence.at(id) = v;
	return 1;
}

cJSON* Entity::toJson() {
	/*
	{
		"id": "this->is",
		"typeId": "this->typeId",
		"name": "this->name",
	 */
	cJSON *root;
	root = cJSON_CreateObject();
	cJSON_AddNumberToObject(root, "id", this->id);
	cJSON_AddStringToObject(root, "typeId", TypeNames[this->typeId]);
	cJSON_AddStringToObject(root, "name", this->name.c_str());
	cout << cJSON_Print(root) << endl;

	return root;
}

Entity::~Entity(void) {}
