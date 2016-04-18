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

TEST_CASE("Test_File", "[file]")
{
	SECTION("Chargement FICHIER")
	{
            int loadResult = Characteristics::loadCharacteristicsFile(PATH_DATA"/descriptionCharacteristics.json");

            REQUIRE( loadResult != -1 );

            std::cout << "I loaded the file !" << std::endl;

            for (auto it = begin (Characteristics::listCharacteristics); it != end (Characteristics::listCharacteristics); ++it) {
                std::cout << it->getType() << std::endl ;
            }

            Sentient_Entity * agent = Factories::createAgent();
            std::cout << agent->getName() << std::endl;

	}
}
