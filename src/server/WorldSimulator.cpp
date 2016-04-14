/**
 * \file WorldSimulator.cpp
 * \brief Implementation of WorldSimulator.hpp
 */
#include "WorldSimulator.hpp"

WorldSimulator::WorldSimulator(bool logAi, bool logWorld) :
WorldSimulator()
{
	if(logAi){ // Log ai infos
		aiLogger = new Logger("ai.log");
	}
	if(logWorld){ // Log world infos
		worldLogger = new Logger("world.log");
	}
}
WorldSimulator::WorldSimulator(){
	aiLogger = NULL;
	worldLogger = NULL;
	
}

void WorldSimulator::run(){
	cout << "Simulation server running" << endl;
	// TODO
	
}
