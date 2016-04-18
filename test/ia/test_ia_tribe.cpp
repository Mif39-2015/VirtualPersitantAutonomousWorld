#include <iostream>
#include <string>
#include <sstream>

#include "serveur_catch.hpp"

#include "ia/Behavior/Action.hpp"
#include "ia/Behavior/ActionComportement.hpp"
#include "ia/Behavior/ActionSimple.hpp"
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

TEST_CASE("Test_Tribe", "[tribe]")
{

	SECTION("TEST TRIBE")
	{
		cout << "TEST TRIBE" << endl;
		int loadResult = Item::loadItemsFile(PATH_DATA"/descriptionItems.txt");

		REQUIRE(Item::listItems.size() != 0);

		Tribe* t = Factories::createTribe();
		REQUIRE(t != NULL);
		t->setName("Anishinaabe");
		REQUIRE(t->getName() == "Anishinaabe");
		t->addItemToStock(&(Item::listItems[1]), 5);

		REQUIRE(t->getQuantityByItem(&(Item::listItems[1])) == 5);
		t->addItemToStock(&(Item::listItems[0]), 10);
		cout << "Le stock du tribu " << t->getName() << " :" << endl;
		t->afficheStock();

		Sentient_Entity * agent = Factories::createAgent();
		cout << "on a créé l'agent " << endl;
		Sentient_Entity * animal = Factories::createAnimal();
		cout << "on a créé l'animal " << endl;
		t->addNewEntity(agent);
		cout << "on l'a ajouté l'agent dans le tribe" << endl;
		t->addNewEntity(animal);
		cout << "on l'a ajouté l'animal dans le tribe" << endl;
		cout << "le nb des entités dans tribe: " << t->getTribeSize() << endl;

		cout << "le type de l'entité: " << agent->getTypeId() << " -- le type de agent2: " << animal->getTypeId() << endl;
	}
}