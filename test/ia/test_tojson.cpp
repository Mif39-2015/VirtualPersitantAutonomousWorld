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

#include "ia/Facade.hpp"

TEST_CASE("Test toJSON", "[toJSON]")
{
	bool loadResult = loadAllFiles();
	REQUIRE(loadResult);
	REQUIRE(Item::listItems.size() != 0);
	
	Facade facade;
	facade.initSimulation(2,2);

	Tribe* t = Factories::createTribe();
	facade.listTribe.push_back(t);
	
	t->addNewEntity(facade.getAgentById(5));
	t->addItemToStock(&(Item::listItems[0]), 10);
	
	facade.getAgentById(5)->addItemToStock(&(Item::listItems[1]), 10);
	
	std::string s1 = facade.serializeEntities();
	
	std::cout<<s1<<std::endl;
	
	std::string s2 = facade.serializeEntitiesIfModified();
	
	std::cout<<s2<<std::endl;

	(facade.getAgentById(5))->setName("Barbapapa");
	
	std::string s3 = facade.serializeEntitiesIfModified();
		
	std::cout<<s3<<std::endl;
	
}
