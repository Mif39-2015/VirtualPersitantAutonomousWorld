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
	
	// Listen for user commands
	handleUserCommands();
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
		if(updatesOccured()){
			if(aiLogger != NULL){
				aiLogger->log("\n####################");
				aiLogger->log("Step " + to_string(simulationTime));
				aiLogger->log("Nb agents \t= " + to_string(facade->listAgent.size()));
				aiLogger->log("Nb tribes \t= " + to_string(facade->listTribe.size()));
				aiLogger->log("Nb objects \t= " + to_string(facade->listIE.size()));
				
				// Log changes of agents
				aiLogger->log("____________________");
				aiLogger->log("Updated agents");
				for(Sentient_Entity * a : facade->listAgent){
					if(a->getModif()){
						aiLogger->log(a->getName());
					}
				}
				
				// Log changes of tribes
				aiLogger->log("____________________");
				aiLogger->log("Updated tribes");
				for(Tribe * t : facade->listTribe){
					if(t->getModif()){
						aiLogger->log(t->getName());
					}
				}
			}
			
			// Log changes to the world
				aiLogger->log("____________________");
				aiLogger->log("Updated objects");
			if(worldLogger != NULL){
				for(Entity* e : facade->getUpdatedAgents()){
					worldLogger->log(e->getName());
				}
			}
		}
		
		/* Broadcasting changes */
		
		
		
		
		/* Reset update flags of world elements (agents, objects, tribes) */
		for(Sentient_Entity * a : facade->listAgent){
			a->setModif(false);
		}
		for(Tribe * t : facade->listTribe){
			t->setModif(false);
		}
		for(Insentient_Entity * ie : facade->listIE){
			ie->setModif(false);
		}
	}
}

void WorldSimulator::handleUserCommands(){
	cout << "Available commands :" << endl;
	cout << "\tload <file>\t: Stops the simulation and replaces it with the simulation in <file>" << endl;
	cout << "\tpause\t: Pauses the simulation" << endl;
	cout << "\tsave <file>\t: Saves the current state of the simulation in <file>" << endl;
	cout << "\tstop\t: Stops the simulation and closes the program" << endl;
	
	string input = "";
	getline(cin, input);
	
	vector<string> words = StringTool::split(input, ' ');
	
	if(words.size() > 0){
		if(words[0].compare("load")){
			if(words.size() > 1){
				this->load(words[1]);
			}
		} else if(words[0].compare("pause")){
			// TODO
		} else if(words[0].compare("save")){
			if(words.size() > 1){
				this->save(words[1]);
			}
		} else if(words[0].compare("stop")){
			// TODO
		}
	}
}

bool WorldSimulator::updatesOccured(){
	return facade->getUpdatedAgents().size() > 0;
}

void WorldSimulator::save(const string fileName){
	// TODO
}

void WorldSimulator::load(const string fileName){
	// TODO
}
