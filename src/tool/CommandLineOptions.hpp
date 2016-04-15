/**
 * \file CommandLineOptions.hpp
 * \brief CommandLineOptions class definition
 */
#ifndef _COMMANDLINEOPTIONS_
#define _COMMANDLINEOPTIONS_

#include <iostream>
#include <fstream>

#include <boost/program_options/options_description.hpp>
#include <boost/program_options/parsers.hpp>
#include <boost/program_options/variables_map.hpp>

using namespace std;
namespace po = boost::program_options;

/**
 * \class CommandLineOptions
 * \brief Holds command line options
 */
class CommandLineOptions {
	private:
		bool logNetwork;
		bool logAi;
		bool logWorld;
		
		CommandLineOptions();
		CommandLineOptions(bool _logNetwork, bool _logAi, bool _logWorld);
	public:
		CommandLineOptions(int argc, char** argv); // From command line
		
		
		bool isLogNetwork();
		bool isLogAi();
		bool isLogWorld();
		
		void setLogNetwork(bool _logNetwork);
		void setLogAi(bool _logAi);
		void setLogWorld(bool _logWorld);
};

#endif
