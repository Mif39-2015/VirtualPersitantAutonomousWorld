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

TEST_CASE("Test toJSON", "[toJSON]")
{
	bool loadResult = loadAllFiles();
	REQUIRE(loadResult);
	REQUIRE(Item::listItems.size() != 0);
		
	Tribe* t = Factories::createTribe();
	Sentient_Entity * agent = Factories::createAgent();
	t->addNewEntity(agent);
	
	t->addItemToStock(&(Item::listItems[0]), 10);
	t->addItemToStock(&(Item::listItems[1]), 10);
	//REQUIRE(t->getQuantityByItem(&(Item::listItems[0])) == 10);
	t->afficheStock();
	
	t->toJson();
	cout << cJSON_Print(t->toJson()) << endl;
	
}
