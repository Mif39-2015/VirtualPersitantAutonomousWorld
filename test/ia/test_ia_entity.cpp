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

TEST_CASE("Test_Agent", "[agent]")
{
	SECTION("TEST AGENT")
	{
		std::cout << "TEST AGENT" << std::endl << std::endl;
		bool loadResult = loadAllFiles();
		REQUIRE(loadResult);


		Sentient_Entity * agent = Factories::createAgent();
		REQUIRE(agent != nullptr);
		Sentient_Entity * agent1 = Factories::createAnimal();
		REQUIRE(agent1 != nullptr);
		Insentient_Entity *building1 = Factories::createBuilding();
		REQUIRE(building1 != nullptr);
		Insentient_Entity *ress = Factories::createResource(T_BOIS);
		REQUIRE(ress != nullptr);
	}

	SECTION("TEST AGENT LIFE")
	{
		std::cout << "TEST AGENT LIFE" << std::endl << std::endl;
		bool loadResult = loadAllFiles();
		REQUIRE(loadResult);

		Sentient_Entity * agent = Factories::createAgent();
		REQUIRE(agent != nullptr);

		int time = 0;
		while ( time < 500) {
			agent->decade(time);
			agent->setIdle(false);
			if (agent->isHungry() == 1) std::cout << "J'ai faim à " << time << " ticks" << std::endl;
			if (agent->isTired() == 1) std::cout << "Je suis crevé à " << time << " ticks" << std::endl;
			time++;
		}
	}

	SECTION("TEST AGENT RECOLTE")
	{
		std::cout << "TEST AGENT RECOLTE" << std::endl << std::endl;
		bool loadResult = loadAllFiles();
		REQUIRE(loadResult);

		Sentient_Entity * agent = Factories::createAgent();
		REQUIRE(agent != nullptr);
		Insentient_Entity *ress = Factories::createResource(T_BOIS);
		REQUIRE(ress != nullptr);

		unsigned int t = 0;
		while(t < 200){
			t++;
			ress->updateResource(t);
			agent->harvestResource(ress);
			ress->afficheStock();
		}
	}
}
