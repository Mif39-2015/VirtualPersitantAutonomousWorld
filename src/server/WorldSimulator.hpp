/**
 * \file WorldSimulator.hpp
 * \brief WorldSimulator class definition
 */
#ifndef _WORLDSIMULATOR_
#define _WORLDSIMULATOR_

#include <iostream>
#include <thread>

#include "WorldSimulator.hpp"
#include "../reseau/NetworkAdapter.hpp"
#include "../logging/Logger.hpp"


class NetworkAdapter;

using namespace std;

/**
 * \class WorldSimulator
 * \brief Main thread that runs the simulation
 */
class WorldSimulator {
	private:
		Logger* aiLogger;
		Logger* worldLogger;
		NetworkAdapter* netAdapter;
	public:
		WorldSimulator();
		WorldSimulator(bool logAi, bool logWorld);
		void run(bool multiThread);
		void worldDoOneLoop();
		void save(const string fileName);
		void load(const string fileName);
};

#endif
