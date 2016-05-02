#include <iostream>
#include <string>
#include <sstream>

#include "serveur_catch.hpp"
#include "ia/Behavior/Comportement.hpp"
#include "ia/Tools/Tools.hpp"

#include "server/WorldSimulator.hpp"

using namespace std;

TEST_CASE("Test_Simulation", "[init]")
{
	SECTION("Init")
	{
		bool loadResult = loadAllFiles();
		REQUIRE(loadResult);

        WorldSimulator ws = WorldSimulator(10, 3, true, true);
		ws.run();
	}
}
