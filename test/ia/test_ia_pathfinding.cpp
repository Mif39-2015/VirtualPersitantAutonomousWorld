#include <iostream>
#include <string>
#include <sstream>

#include "serveur_catch.hpp"

#include "ia/Behavior/Action.hpp"
#include "ia/Behavior/Arete.hpp"
#include "ia/Behavior/Comportement.hpp"
#include "ia/Behavior/EtatEnum.hpp"
#include "ia/Behavior/FonctionEnums.hpp"
#include "ia/Behavior/Noeud.hpp"

#include "ia/Entity/Characteristics.hpp"
#include "ia/Entity/Entity.hpp"
#include "ia/Entity/Insentient_Entity.hpp"
#include "ia/Entity/Item.hpp"
#include "ia/Entity/Sentient_Entity.hpp"
#include "ia/Entity/Tangible_Entity.hpp"
#include "ia/Entity/Tribe.hpp"

#include "ia/Tools/Factories.hpp"
#include "ia/Tools/Position.hpp"
#include "ia/Tools/Astar.hpp"

using namespace std;

TEST_CASE("Test_Pathfinding", "[astar]")
{
	SECTION("AStar")
	{
		int xDep = 0;
		int yDep = 1;
		int xArr = 5;
		int yArr = 10;

		stack<Position> chemin = pathFind(xDep, yDep, xArr, yArr);
		while (!chemin.empty()) {
			cout << chemin.top().getX() << ";" << chemin.top().getY() << endl;
			chemin.pop();
		}
	}

}
