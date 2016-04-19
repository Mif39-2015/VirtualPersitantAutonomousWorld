#include <iostream>
#include <string>
#include <sstream>

#include "serveur_catch.hpp"
#include "ia/Behavior/Comportement.hpp"

#include "server/WorldSimulator.hpp"

using namespace std;

TEST_CASE("Test_Simulation", "[init]")
{
	SECTION("Init")
	{
		// Load behaviours
		int loadResult = Characteristics::loadCharacteristicsFile(PATH_DATA"/descriptionCharacteristics.json");
		int loadResult2 = Comportement::initVectorComp(PATH_DATA"foo.json");

        WorldSimulator ws = WorldSimulator(10, 10, true, true);
		ws.run(false);
	}
}
