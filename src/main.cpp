#include <iostream>

#include "tools/CommandLineOptions.hpp"
#include "server/WorldSimulator.hpp"


int main(int argc, char** argv)
{
	CommandLineOptions options(argc, argv);
	WorldSimulator simulator(options.isLogAi(), options.isLogWorld());
	
	
    return 0;
}
