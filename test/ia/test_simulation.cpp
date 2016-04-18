#include <iostream>
#include <string>
#include <sstream>

#include "serveur_catch.hpp"

#include "server/WorldSimulator.hpp"

using namespace std;

TEST_CASE("Test_Simulation", "[init]")
{
	SECTION("Init")
	{
        WorldSimulator ws = WorldSimulator(10, 10, true, true);
		ws.run(false);
	}
}
