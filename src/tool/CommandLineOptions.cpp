/**
 * \file CommandLineOptions.cpp
 * \brief Implementation of CommandLineOptions.hpp
 */
#include "CommandLineOptions.hpp"


CommandLineOptions::CommandLineOptions(bool _logNetwork, bool _logAi, bool _logWorld) :
logNetwork(_logNetwork), logAi(_logAi), logWorld(_logWorld)
{
	
}

CommandLineOptions::CommandLineOptions() :
logNetwork(false), logAi(false), logWorld(false)
{
	
}

CommandLineOptions::CommandLineOptions(int argc, char** argv){
	po::options_description general_opt("OPTIONS");
    general_opt.add_options()
        ("help,h", "displays this message")
        ("network,n", "log network data")
        ("ai,ai", "log ai data")
        ("world,w", "log world data");
        //~ ("period,p", po::value<unsigned int>()->default_value(30), "periode de tic d'horloge pour la boucle principale (en secondes)" );

    // Vérification de la validité des arguments
    bool parse_ok = true;
    po::variables_map vm;

    try {
        po::store(po::parse_command_line(argc, argv, general_opt), vm);
    } catch(const std::exception& ex) {
        parse_ok = false;
        std::cerr << "Error in program options : " << ex.what() << std::endl;
    }

    po::notify(vm);

    if( !parse_ok || vm.count("help"))
    {
        std::cout << "Use: " << argv[0] << " [OPTIONS]" << endl
			<< general_opt << std::endl;
        return;
    }


    if(vm.count("network"))
    {
		setLogNetwork(true);
    }

    if(vm.count("ai"))
    {
        setLogAi(true);
    }

    if(vm.count("world"))
    {
        setLogWorld(true);
    }
}


bool CommandLineOptions::isLogNetwork(){
	return logNetwork;
}

bool CommandLineOptions::isLogAi(){
	return logAi;
}

bool CommandLineOptions::isLogWorld(){
	return logWorld;
}


void CommandLineOptions::setLogNetwork(bool _logNetwork){
	logNetwork = _logNetwork;
}

void CommandLineOptions::setLogAi(bool _logAi){
	logAi = _logAi;
}

void CommandLineOptions::setLogWorld(bool _logWorld){
	logWorld = _logWorld;
}

