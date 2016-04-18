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
#include "Tools/Position.hpp"
#include "Tools/Astar.hpp"

using namespace std;

TEST_CASE("Test_File", "[file]")
{
	SECTION("Chargement FICHIER")
	{
		// int loadResult = Characteristics::loadCharacteristicsFile("data/descriptionCharacteristics.txt");
		int loadResult = Characteristics::loadCharacteristicsFile("../../../data/descriptionCharacteristics.txt");

		REQUIRE( loadResult != -1 );

		std::cout << "I loaded the file !" << std::endl;

		for (auto it = begin (Characteristics::listCharacteristics); it != end (Characteristics::listCharacteristics); ++it) {
			std::cout << it->getType() << std::endl ;
		}

		Sentient_Entity * agent = Factories::createAgent();
		std::cout << agent->getName() << std::endl;

	}
}

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

TEST_CASE("Test_Comportement", "[comp]")
{
	SECTION("TEST COMPORTEMENT")
	{

		int loadResult = Characteristics::loadCharacteristicsFile(PATH_DATA"/descriptionCharacteristics.txt");

		cout << "ICI, ON TESTE LE COMPORTEMENT" << endl;

		Comportement * c =  new Comportement();

		Noeud noeudFaimM5;
		Noeud noeudFaimP10;

		Arete areteFaim20(&noeudFaimM5, &noeudFaimP10);
		Arete areteFaim80(&noeudFaimP10, &noeudFaimM5);

		cout << "declaration des Aretes" << endl;

        noeudFaimM5.ajouterAreteOut(&areteFaim20);
        noeudFaimM5.ajouterAreteIn(&areteFaim80);
        noeudFaimP10.ajouterAreteIn(&areteFaim20);
        noeudFaimP10.ajouterAreteOut(&areteFaim80);

		ActionSimple actionFaimM5;
		ActionSimple actionFaimP10;

		actionFaimM5.setFonc_Void(FONC_FAIM_M5);
		actionFaimP10.setFonc_Void(FONC_FAIM_P10);

		cout << "Setup des Actions" << endl;

		noeudFaimM5.setAction(&actionFaimM5);
		noeudFaimP10.setAction(&actionFaimP10);

		cout << "On a inséré les actions dans les noeuds" << endl;

		vector<struct_condition> vecStructCondFaim20;
		struct_condition condFaim20;
		condFaim20.fIE1 = Fonc_GetFaim;
		condFaim20.e1 = nullptr;
		condFaim20.op = Inf;
		condFaim20.comp = 20;
		condFaim20.fIE2 = FONC_I_E_NULL;
		vecStructCondFaim20.push_back(condFaim20);

		cout << "on a mis la condition dans le vecteur" << endl;

		areteFaim20.setCondition_Complexe(vecStructCondFaim20);

		cout << "on a mis le vecteur dans l'arete" << endl;

		vector<struct_condition> vecStructCondFaim80;
		struct_condition condFaim80;
		condFaim80.fIE1 = Fonc_GetFaim;
		condFaim80.e1 = nullptr;
		condFaim80.op = Sup;
		condFaim80.comp = 80;
		condFaim80.fIE2 = FONC_I_E_NULL;
		vecStructCondFaim80.push_back(condFaim80);
		areteFaim80.setCondition_Complexe(vecStructCondFaim80);

		cout << "pareil pour l'autre arete " << endl;

		c->ajouterNoeud(&noeudFaimM5);
		c->ajouterNoeud(&noeudFaimP10);

		cout << "on ajoute les noeuds dans le comportement " << endl;

		Sentient_Entity * agent = Factories::createAgent();

		cout << "on a créé l'agent " << endl;

		agent->addToTrace(c, &noeudFaimM5, false);

		cout << "on a ajouté le comportement dans l'agent" << endl;

		for (int i = 0; i < 100; ++i) {
			cout << endl << "##### iteration " << i << " : " << endl;
			agent->run();
		}

		delete c;

	}
}

TEST_CASE("Test_Item", "[item]")
{
	SECTION("TEST ITEM")
	{
		cout << "TEST ITEM" << endl;
		int loadResult = Item::loadItemsFile(PATH_DATA"/descriptionItems.txt");

		REQUIRE(Item::listItems.size() != 0);

		Tribe* t = Factories::createTribe();
		REQUIRE(t != NULL);

		t->addItemToStock(&(Item::listItems[0]), 3);

		REQUIRE(t->getQuantityByItem(&(Item::listItems[0])) == 3);

		t->afficheStock();

		Sentient_Entity* ag = Factories::createAgent();
		REQUIRE(ag != nullptr);

		ag->addItemToStock(&(Item::listItems[0]), 18);

		REQUIRE(ag->getQuantityByItem(&(Item::listItems[0])) == 18);

		ag->afficheStock();
	}
}

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

TEST_CASE("Test_Facade", "[facade]")
{
	SECTION("Facade")
	{

	}
}
