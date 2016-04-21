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
		// Load behaviours
		// int loadResult = Characteristics::loadCharacteristicsFile(PATH_DATA"/descriptionCharacteristics.json");
		// int loadResult2 = Comportement::initVectorComp(PATH_DATA"foo.json");
		bool loadResult = loadAllFiles();
		REQUIRE(loadResult);

        WorldSimulator ws = WorldSimulator(1, 1, true, true);
		ws.run();
	}
}
