#include "ia/Facade.hpp"

void Facade::runAll(){
	for(Sentient_Entity * se : Facade::listAgent){
		if(se->getTypeId() == type::ID_AGENT || se->getTypeId() == type::ID_ANIMAL){
			se->run();
		}
	}
}

void Facade::updateWorld(){
	//Fonction qui va mettre à jour tout les insentient_entity
	//a chaque tick (ressource, etc)
}

Sentient_Entity * Facade::getAgentById(unsigned int i){
	for(Sentient_Entity * se : Facade::listAgent){
		if(se->getId() == i){
			return se;
		}
	}
	return nullptr;
}

Tribe * Facade::getTribeById(unsigned int i){
	for(Tribe * t : Facade::listTribe){
		if(t->getId() == i){
			return t;
		}
	}
	return nullptr;
}

void Facade::initSimulation(int nbAg, int nbAn){
	//Création de nbAg agents
	for(int iag = 0; iag < nbAg; iag++){
		Facade::listAgent.push_back(Factories::createAgent());
	}

	//Création de nbAn animaux
	for(int ian = 0; ian < nbAn; ian++){
		Facade::listAgent.push_back(Factories::createAnimal());
	}

	//Création des Ressources en fonction des données de la map
	//TODO

	//Création de la tribu de neutre (de base)

}

std::vector<Entity *> Facade::getUpdatedAgents(){
	std::vector<Entity *> updatedObjects;
	for(Tribe * t : Facade::listTribe){
		if(t->getModif()){
			updatedObjects.push_back(t);
		}
	}
	for(Sentient_Entity * a : Facade::listAgent){
		if(a->getModif()){
			updatedObjects.push_back(a);
		}
	}
	for(Insentient_Entity * ie : Facade::listIE){
		if(ie->getModif()){
			updatedObjects.push_back(ie);
		}
	}
	
	return updatedObjects;
}
