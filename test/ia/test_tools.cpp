#include <iostream>
#include <string>
#include <sstream>

#include "serveur_catch.hpp"

#include "Behavior/Action.hpp"
#include "Behavior/Arete.hpp"
#include "Behavior/Comportement.hpp"
#include "Behavior/EtatEnum.hpp"
#include "Behavior/FonctionEnums.hpp"
#include "Behavior/Noeud.hpp"

#include "Entity/Characteristics.hpp"
#include "Entity/Entity.hpp"
#include "Entity/Insentient_Entity.hpp"
#include "Entity/Item.hpp"
#include "Entity/Sentient_Entity.hpp"
#include "Entity/Tangible_Entity.hpp"
#include "Entity/Tribe.hpp"

#include "Tools/Factories.hpp"

using namespace std;
TEST_CASE("Test tools", "[tools]")
{
	SECTION("Test classe Position")
	{
		Position p1 (0,0);
		Position* p2 = new Position(2,2);

		REQUIRE(!(p1.isInCircle(p2, 1)));

		REQUIRE(p1.isInCircle(p2, 8));
	}
}
