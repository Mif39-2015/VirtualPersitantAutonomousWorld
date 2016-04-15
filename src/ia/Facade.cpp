#include "Facade.hpp"

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

void Facade::initSimulation(int nbAg){

}