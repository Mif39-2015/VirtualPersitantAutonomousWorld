/**
 * \file WorldSimulator.cpp
 * \brief Implementation of WorldSimulator.hpp
 */
#include "server/WorldSimulator.hpp"

mutex guardMutex;
condition_variable guardCV;
SimulationState state;

WorldSimulator::WorldSimulator(int nbAgents, int nbAnimals, bool logAi, bool logWorld)
: 	netAdapter(new NetworkAdapter(this)),
	simulationTime(0),
	simulationTimeWarp(100000),
	facade(new Facade()),
	// state(SimulationState::IDLE_SIMULATION),
	multiThread(false)
{
	facade->initSimulation(nbAgents, nbAnimals);
	state = SimulationState::IDLE_SIMULATION;
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

void WorldSimulator::run(){
	state = SimulationState::RUNNING_SIMULATION;

	// Listen for user commands
	thread userCommandsHandlerThread(&WorldSimulator::handleUserCommands, this);

	if(multiThread){
		// TODO
	} else {
		thread worldThread(&WorldSimulator::worldRun, this);

		worldThread.join();
	}

	userCommandsHandlerThread.join();
	return;
}

void WorldSimulator::worldRun(){
	/* World run method */
	while(state != SimulationState::STOPPING_SIMULATION){
		// this_thread::sleep_for( chrono::milliseconds( 1000 ));

		if(state == SimulationState::PAUSED_SIMULATION){
			unique_lock<mutex> lk(guardMutex);
        	guardCV.wait(lk);
		}

		if(state == SimulationState::REQUIRE_WAIT_SIMULATION){
			// Signal the user commands handler thread that no more actions are being performed
			// so it can start the saving procedure
			{
				lock_guard<mutex> lk(guardMutex);
				state = SimulationState::WAITING_SIMULATION;
			}

			guardCV.notify_one();
			// Wait for the saving process to end
			{
				unique_lock<mutex> lk(guardMutex);
	        	guardCV.wait(lk);
	        }
		}

		facade->runAll();
		facade->updateWorld(simulationTime);

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

		// TODO


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

		// Increase time counter
		simulationTime++;
		simulationTime %= simulationTimeWarp;
	}
}

void WorldSimulator::handleUserCommands(){
	displayUserCommands();
	while(state != SimulationState::STOPPING_SIMULATION){
		// cout << "s = " << state << endl;
		cout << " > ";
		string input = "";
		getline(cin, input);

		vector<string> words = StringTool::split(input, ' ');
		// cout << words.size() << endl;
		// cout << words[0] << endl;
		if(words.size() > 0){
			// cout << words[0] << endl;
			if(words[0].compare("help") == 0 || words[0].compare("h") == 0 || words[0].compare("?") == 0){
				this->displayUserCommands();
			} else if(words[0].compare("load") == 0){
				if(words.size() > 1){
					this->load(words[1]);
				} else {
					cout << "\tMissing parameter \"file\". Usage : load <file>" << endl;
				}
			} else if(words[0].compare("pause") == 0){
				if(state != SimulationState::PAUSED_SIMULATION){
					state = SimulationState::PAUSED_SIMULATION;
				} else {
					cout << "\tThe simulation is already paused" << endl;
				}
			} else if(words[0].compare("resume") == 0){
				if(state == SimulationState::PAUSED_SIMULATION){
					lock_guard<mutex> lk(guardMutex);
					state = SimulationState::RUNNING_SIMULATION;
					guardCV.notify_one();
				} else {
					cout << "\tYou can only resume the simulation when it is paused" << endl;
				}
			} else if(words[0].compare("save") == 0){
				if(words.size() > 1){
					this->save(words[1]);
				} else {
					cout << "\tMissing parameter \"file\". Usage : save <file>" << endl;
				}
			} else if(words[0].compare("stop") == 0){
				state = SimulationState::STOPPING_SIMULATION;
			} else {
				cout << "\tUnknown command \"" << words[0] << "\". You can list available commands by typing \"help\"" << endl;
			}
		} else {
			// cout << "\tUnknown command. You can list available commands by typing \"help\"" << endl;
		}
	}

}


void WorldSimulator::displayUserCommands(){
	cout << "Available commands :" << endl;
	cout << "\thelp, h, ?\t: Displays this help" << endl;
	cout << "\tload <file>\t: Stops the simulation and replaces it with the simulation in <file>" << endl;
	cout << "\tpause\t\t: Pauses the simulation" << endl;
	cout << "\tresume\t\t: Resumes the simulation if it was paused" << endl;
	cout << "\tsave <file>\t: Saves the current state of the simulation in <file>" << endl;
	cout << "\tstop\t\t: Stops the simulation and exits the program" << endl;
}

bool WorldSimulator::updatesOccured(){
	return facade->getUpdatedAgents().size() > 0;
}

void WorldSimulator::save(const string fileName){
	state = SimulationState::REQUIRE_WAIT_SIMULATION;

	// Wait for server step to finish
	{
		unique_lock<mutex> lk(guardMutex);
	    guardCV.wait(lk);
	}



	cout << "Saving... " << endl;
    // TODO save world data to file


	this_thread::sleep_for( chrono::milliseconds( 2000 ));


	cout << "Done saving" << endl;

	// Signal simulation that the saving process is now over
	{
		lock_guard<mutex> lk(guardMutex);
	    state = SimulationState::RUNNING_SIMULATION;
	}


    // Allow simulation to resume
    guardCV.notify_one();

}

void WorldSimulator::load(const string fileName){
	state = SimulationState::REQUIRE_WAIT_SIMULATION;

	// Wait for server step to finish
	{
		unique_lock<mutex> lk(guardMutex);
	    guardCV.wait(lk);
	}



	cout << "Loading... " << endl;
    // TODO load world data from file


	this_thread::sleep_for( chrono::milliseconds( 2000 ));


	cout << "Done Loading" << endl;

	// Signal simulation that the loading process is now over
	{
		lock_guard<mutex> lk(guardMutex);
	    state = SimulationState::RUNNING_SIMULATION;
	}


    // Allow simulation to resume
    guardCV.notify_one();
}
