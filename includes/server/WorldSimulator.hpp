/**
 * \file WorldSimulator.hpp
 * \brief WorldSimulator class definition
 */
#ifndef _WORLDSIMULATOR_
#define _WORLDSIMULATOR_

#include <iostream>
#include <thread>

#include "server/WorldSimulator.hpp"
#include "reseau/NetworkManager.hpp"
#include "logging/Logger.hpp"


class NetworkManager;

using namespace std;

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
		 * \brief Runs one step of the world simulation.
		 * Called every step by the run method when multithread argument is false
		 **/
		void worldDoOneLoop();
	public:
		/*!
		 * \brief No-arg constructor.
		 * Equivalent to WorldSimulator(false, false)
		 **/
		WorldSimulator();

		/*!
		 * \brief Constructor with logging parameters.
		 **/
		WorldSimulator(bool logAi, bool logWorld);

		/*!
		 * \brief Runs the simulation.
		 * multiThread parameter determines if there must be
		 * only one thread or if each agent must have a dedicated thread
		 **/
		void run(bool multiThread);

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
