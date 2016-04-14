/**
 * \file WorldSimulator.hpp
 * \brief WorldSimulator class definition
 */
#ifndef _WORLDSIMULATOR_
#define _WORLDSIMULATOR_

#include <iostream>
#include "WorldSimulator.hpp"
#include "../logging/Logger.hpp"

using namespace std;

/**
 * \class WorldSimulator
 * \brief Main thread that runs the simulation
 */
class WorldSimulator {
	private:
		Logger* aiLogger;
		Logger* worldLogger;
	public:
		WorldSimulator();
		WorldSimulator(bool logAi, bool logWorld);
		void run();
};

#endif
