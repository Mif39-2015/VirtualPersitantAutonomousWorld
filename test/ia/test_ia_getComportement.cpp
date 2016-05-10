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

#include "ia/Tools/Tools.hpp"

using namespace std;

TEST_CASE("Test_GetComportement", "[getComp]")
{
	SECTION("Parsing de Comportement")
	{
		cout << " on essaie de parser " << PATH_DATA"/behavior_test.json" << endl;
		REQUIRE(true);
		int l = getComportements(PATH_DATA"/behavior_test.json");
		REQUIRE(true);
		cout << " FIN DU TEST FFS " << endl;
		REQUIRE(l != 0);
	}
}
