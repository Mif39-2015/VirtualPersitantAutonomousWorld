/**
 * \file WorldSimulator.hpp
 * \brief WorldSimulator class definition
 */
#ifndef _WORLDSIMULATOR_
#define _WORLDSIMULATOR_

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <signal.h>

#include "ia/Facade.hpp"
#include "reseau/NetworkAdapter.hpp"
#include "logging/Logger.hpp"
#include "tool/StringTool.hpp"

#include "server/WorldSimulator.hpp"
#include "reseau/NetworkManager.hpp"
#include "logging/Logger.hpp"


class NetworkManager;

using namespace std;

enum SimulationState {
	IDLE_SIMULATION,
	PAUSED_SIMULATION,
	REQUIRE_WAIT_SIMULATION,
	RUNNING_SIMULATION,
	WAITING_SIMULATION,
	STOPPING_SIMULATION
};

/**
 * \class WorldSimulator
 * \brief Main thread that runs the simulation
 */
class WorldSimulator {
	private:
		/*!
		 * \brief logs AI changes, states, etc
		 * /!\ This object will be NULL if corresponding
		 * constructor parameter wasn't set to true
		 **/
		Logger* aiLogger;

		/*!
		 * \brief logs World objects, changes, etc
		 * /!\ This object will be NULL if corresponding
		 * constructor parameter wasn't set to true
		 **/
		Logger* worldLogger;

		/*!
		 * \brief Sends and receives data to/from clients via the network
		 **/
		NetworkManager* netManager;

		/*!
		 * \brief the simulation time (number of steps)
		 **/
		unsigned int simulationTime;
		
		/*!
		 * \brief the max value of simulationTime. After this step, simulationTime will warp back to 0
		 **/
		unsigned int simulationTimeWarp;
		
		/*!
		 * \brief Facade to access AI simulation metods and agents
		 **/
		Facade* facade;

		/*!
		 * \brief True if each agent has a dedicated thread
		 **/
		 bool multiThread;

		/*!
		 * \brief Runs one step of the world simulation.
		 * Called every step by the run method when multithread argument is false
		 **/
		void worldRun();
		
		/*!
		 * \brief Catches user commands in the command line and executes it
		 **/
		void handleUserCommands();

		/*!
		 * \brief Displays available commands
		 **/
		void displayUserCommands();

		/*!
		 * \brief Stops the simulation. Called when ctching ctrl+c signal
		 **/
		static void stopSimulation(int sig_num);


	public:
		/*!
		 * \brief No-arg constructor.
		 * Equivalent to WorldSimulator(false, false)
		 **/
		WorldSimulator();

		/*!
		 * \brief Constructor with logging parameters.
		 **/
		WorldSimulator(int nbAgents, int nbAnimals, bool logAi, bool logWorld);
		
		/*!
		 * \brief Runs the simulation.
		 **/
		void run();
		
		/*!
		 * \brief Checks whether or not changes occured during previous simulation step
		 **/
		bool updatesOccured();
		
		/*!
		 * \brief Saves the state of the entire world.
		 * Data is written to the given fileName
		 * Data written contains world objects, user database
		 * and world global data (items, characteristics, etc...)
		 **/
		void save(const string fileName);

		/*!
		 * \brief Creates a simulation starting from a saved file.
		 **/
		void load(const string fileName);
};

#endif
