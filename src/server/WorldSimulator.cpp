/**
 * \file WorldSimulator.cpp
 * \brief Implementation of WorldSimulator.hpp
 */
#include "server/WorldSimulator.hpp"

WorldSimulator::WorldSimulator(int nbAgents, int nbAnimals, bool logAi, bool logWorld)
: 	netAdapter(new NetworkAdapter(this)),
	simulationTime(0),
	simulationTimeWarp(100000),
	facade(new Facade())
{
	facade->initSimulation(nbAgents, nbAnimals);
	
	aiLogger = NULL;
	worldLogger = NULL;
	
	if(logAi){ // Log ai infos
		aiLogger = new Logger("ai.log");
	}
	if(logWorld){ // Log world infos
		worldLogger = new Logger("world.log");
	}
}

WorldSimulator::WorldSimulator()
: WorldSimulator(false, false, 10, 10)
{
	
}

void WorldSimulator::run(bool multiThread){
	cout << "Simulation server running" << endl;
	// TODO
	if(multiThread){
		
	} else {
		thread worldThread(&WorldSimulator::worldRun, this);
		
		worldThread.join();
	}
}

void WorldSimulator::worldRun(){
	/* World run method */
	while(true){
		// Increase time counter
		simulationTime++;
		simulationTime %= simulationTimeWarp;
		
		facade->runAll();
		facade->updateWorld();
		
		/* Logging AI & World */
		if(aiLogger != NULL){
			aiLogger->log("####################");
			aiLogger->log("Step n°" + simulationTime);
			aiLogger->log("Nb agents \t\t= " + facade->listAgent.size());
			aiLogger->log("Nb tribes \t\t= " + facade->listTribe.size());
			aiLogger->log("Nb insentient entities \t= " + facade->listIE.size());
			// Log changes of agents
			for(Sentient_Entity * a : facade->listAgent){
				if(a->getModif()){
					aiLogger->log(a->getName());
				}
			}
			// Log changes of tribes
			for(Tribe * t : facade->listTribe){
				if(t->getModif()){
					aiLogger->log(t->getName());
				}
			}
		}
		if(worldLogger != NULL){
			for(Entity* e : facade->getChanges()){
				worldLogger->log(e->getName());
			}
		}
		
		/* Broadcasting changes */
		
	}
}

void WorldSimulator::save(const string fileName){
	// TODO
}

void WorldSimulator::load(const string fileName){
	// TODO
}
