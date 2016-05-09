#include "ia/Facade.hpp"

void Facade::runAll(unsigned int wstime) {
	for (Sentient_Entity * se : Facade::listAgent) {
		if (se->getTypeId() == type::ID_AGENT || se->getTypeId() == type::ID_ANIMAL) {
			se->run(wstime);
		}
	}
}

void Facade::updateWorld(unsigned int wstime) {
	for(Insentient_Entity * ie : Facade::listIE){
		if(ie->getTypeId() == type::ID_RESSOURCE_BOIS
			|| ie->getTypeId() == type::ID_RESSOURCE_PIERRE
			|| ie->getTypeId() == type::ID_RESSOURCE_METAL
			|| ie->getTypeId() == type::ID_RESSOURCE_VIANDE
			|| ie->getTypeId() == type::ID_RESSOURCE_LEGUME){
			ie->updateResource(wstime);
		}
	}
}

Sentient_Entity * Facade::getAgentById(unsigned int i) {
	for (Sentient_Entity * se : Facade::listAgent) {
		if (se->getId() == i) {
			return se;
		}
	}
	return nullptr;
}

Tribe * Facade::getTribeById(unsigned int i) {
	for (Tribe * t : Facade::listTribe) {
		if (t->getId() == i) {
			return t;
		}
	}
	return nullptr;
}

void Facade::initSimulation(int nbAg, int nbAn) {
	//Création de nbAg agents
	for (int iag = 0; iag < nbAg; iag++) {
		Facade::listAgent.push_back(Factories::createAgent());
	}

	//Création de nbAn animaux
	for (int ian = 0; ian < nbAn; ian++) {
		Facade::listAgent.push_back(Factories::createAnimal());
	}

	//En attendant la map, je crée une ressource pour les tests
	Facade::listIE.push_back(Factories::createResource(ResourceType::T_BOIS));

	//Création des Ressources en fonction des données de la map
	//TODO

	//Création de la tribu de neutre (de base)

}

std::vector<Entity *> Facade::getUpdatedAgents() {
	std::vector<Entity *> updatedObjects;
	for (Tribe * t : Facade::listTribe) {
		if (t->getModif()) {
			updatedObjects.push_back(t);
		}
	}
	for (Sentient_Entity * a : Facade::listAgent) {
		if (a->getModif()) {
			updatedObjects.push_back(a);
		}
	}
	for (Insentient_Entity * ie : Facade::listIE) {
		if (ie->getModif()) {
			updatedObjects.push_back(ie);
		}
	}

	return updatedObjects;
}

void Facade::serializeEntities(){

	cJSON * population;
	population = cJSON_CreateObject();
	
	//serialisation des tribus
	cJSON * tribes;
	tribes = cJSON_CreateArray();
	for (auto it = listTribe.begin(); it != listTribe.end(); it++)
	{
		cJSON_AddItemToArray(tribes, (*it)->toJson());
	}
	cJSON_AddItemToObject(population, "tribes", tribes);
	
	//serialisation des Sentient_Entity (agents/animaux)
	cJSON * ses;
	ses = cJSON_CreateArray();
	for (auto it2 = listAgent.begin(); it2 != listAgent.end(); it2++)
	{
		cJSON_AddItemToArray(ses, (*it2)->toJson());
	}
	cJSON_AddItemToObject(population, "sentient_entities", ses);
	
	//serialisation des Insentient_Entity (batiments/ressources)
	cJSON * ies;
	ies = cJSON_CreateArray();
	for (auto it3 = listIE.begin(); it3 != listIE.end(); it3++)
	{
		cJSON_AddItemToArray(ies, (*it3)->toJson());
	}
	cJSON_AddItemToObject(population, "insentient_entities", ies);
	
	std::cout<<cJSON_Print(population)<<std::endl;
}

void Facade::serializeEntitiesIfModified(){
	
	cJSON * population;
	population = cJSON_CreateObject();
	
	//serialisation des tribus
	std::cout<<"serialisation tribus"<<std::endl;
	cJSON * tribes;
	tribes = cJSON_CreateArray();
	for (auto it = listTribe.begin(); it != listTribe.end(); it++)
	{
		if ((*it)->getModif()){
			cJSON_AddItemToArray(tribes, (*it)->toJson());
			(*it)->reinitModif();
		}
	}
	cJSON_AddItemToObject(population, "tribes", tribes);
	
	//serialisation des Sentient_Entity (agents/animaux)
	std::cout<<"serialisation SE"<<std::endl;
	cJSON * ses;
	ses = cJSON_CreateArray();
	for (auto it2 = listAgent.begin(); it2 != listAgent.end(); it2++)
	{
		if ((*it2)->getModif()){
			cJSON_AddItemToArray(ses, (*it2)->toJson());
			(*it2)->reinitModif();
		}
	}
	cJSON_AddItemToObject(population, "sentient_entities", ses);
	
	//serialisation des Insentient_Entity (batiments/ressources)
	std::cout<<"serialisation IE"<<std::endl;
	cJSON * ies;
	ies = cJSON_CreateArray();
	for (auto it3 = listIE.begin(); it3 != listIE.end(); it3++)
	{
		std::cout<<(*it3)->getModif()<<std::endl;
		if ((*it3)->getModif()){
			cJSON_AddItemToArray(ies, (*it3)->toJson());
			(*it3)->reinitModif();
		}
	}
	cJSON_AddItemToObject(population, "insentient_entities", ies);
	
	std::cout<<cJSON_Print(population)<<std::endl;
}
