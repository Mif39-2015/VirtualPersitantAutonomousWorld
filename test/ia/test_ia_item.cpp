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

TEST_CASE("Test_Item", "[item]")
{
	SECTION("TEST ITEM")
	{
		cout << "TEST ITEM" << endl;
		int loadResult = Item::loadItemsFile(PATH_DATA"/descriptionItems.json");

		REQUIRE(Item::listItems.size() != 0);

		Item * item = Item::getItemByName("Viande");

		REQUIRE(item->getName() == "Viande");

		Tribe* t = Factories::createTribe();
		REQUIRE(t != NULL);

		std::cout << "Stock de t :" << std::endl;
		t->addItemToStock(&(Item::listItems[0]), 3);

		REQUIRE(t->getQuantityByItem(&(Item::listItems[0])) == 3);

		t->afficheStock();

		Sentient_Entity* ag = Factories::createAgent();
		REQUIRE(ag != nullptr);

		ag->addItemToStock(&(Item::listItems[1]), 18);
		ag->addItemToStock(Item::getItemByName("Viande"), 25);

		REQUIRE(ag->getQuantityByItem(Item::getItemByName("Viande")) == 25);

		std::cout << "Stock de ag :" << std::endl;
		ag->afficheStock();

		delete ag;
		delete t;

		std::cout << std::endl;
	}

	SECTION("TEST ITEM REGEN")
	{
		cout << "TEST ITEM REGEN" << endl;
		int loadResult = Item::loadItemsFile(PATH_DATA"/descriptionItems.json");



		std::cout << std::endl;
	}
}
