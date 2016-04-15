/**
 * \file WorldSimulator.cpp
 * \brief Implementation of WorldSimulator.hpp
 */
#include "WorldSimulator.hpp"

WorldSimulator::WorldSimulator(bool logAi, bool logWorld)
: netAdapter(new NetworkAdapter(this))
{
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
: WorldSimulator(false, false)
{
	
}

void WorldSimulator::run(bool multiThread){
	cout << "Simulation server running" << endl;
	// TODO
	if(multiThread){
		
	} else {
		thread worldThread(&WorldSimulator::worldDoOneLoop, this);
		
		worldThread.join();
		
	}
}

void WorldSimulator::worldDoOneLoop(){
	/* World run method */
	/* Logging AI & World */
	/* Broadcasting */
}

void WorldSimulator::save(const string fileName){
	// TODO
}

void WorldSimulator::load(const string fileName){
	// TODO
}
