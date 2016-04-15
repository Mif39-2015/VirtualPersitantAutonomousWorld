#include <iostream>
#include <string>
#include <sstream>
#include <stack>

#include "serveur_catch.hpp"
#include "Entity/Characteristics.hpp"
#include "Tools/Factories.hpp"
#include "Tools/Position.hpp"
#include "Tools/Astar.hpp"
#include "Behavior/Comportement.hpp"
#include "Entity/Sentient_Entity.hpp"
#include "msgpack.hpp"

TEST_CASE("Test IA", "[ia]")
{
    /*
    SECTION("Scenario 1")
    {
        std::string name = "Mykaz";
        type tid = ID_AGENT;
        Sentient_Entity* agent = new Sentient_Entity(Position(0, 0),name,tid);
        Comportement comp;
        Noeud noeudPasFaim;
        Noeud noeudFaim;

        std::vector<FONC_BOOL> vectFctTrue;
        vectFctTrue.push_back(Fonction_BOOL_TRUE);
        Arete areteTrue(&noeudPasFaim,&noeudFaim);

        std::vector<FONC_BOOL> vectFctFalse;
        vectFctFalse.push_back(Fonction_BOOL_FALSE);
        Arete areteFalse(&noeudFaim,&noeudPasFaim);

        noeudPasFaim.addAreteIn(&areteFalse);
        noeudPasFaim.addAreteOut(&areteTrue);
        noeudFaim.addAreteIn(&areteTrue);
        noeudFaim.addAreteOut(&areteFalse);

        Noeud* noeudCourant = &noeudPasFaim;

        comp.ajouterNoeud(&noeudPasFaim);
        comp.ajouterNoeud(&noeudFaim);

        for(int i = 0; i < 5; i++){
            std::cout << "Noeud courant : " << noeudCourant<< agent->getEtat_Entity() << std::endl;
            agent->setEtat_Entity(3);
            noeudCourant = noeudCourant->executerNoeud(agent);
        }
    }
    */

    SECTION("Scenario 2")
    {
        // int loadResult = CharacteristicsList::loadCharacteristicsFile("data/descriptionCharacteristics.txt");
        int loadResult = CharacteristicsList::loadCharacteristicsFile("../../../data/descriptionCharacteristics.txt");

        REQUIRE( loadResult != -1 );

        std::cout << "I loaded the file !" << std::endl;

        for (auto it = begin (CharacteristicsList::listCharacteristics); it != end (CharacteristicsList::listCharacteristics); ++it) {
            std::cout <<it->getType() << std::endl ;
        }

        Sentient_Entity * agent = Factories::createAgent();
        std::cout << agent->getName() << std::endl;

    }

    SECTION("Test de msgpack")
    {
        msgpack::type::tuple<int, bool, std::string> src(1, true, "example");

        // serialize the object into the buffer.
        // any classes that implements write(const char*,size_t) can be a buffer.
        std::stringstream buffer;
        msgpack::pack(buffer, src);

        // send the buffer ...
        buffer.seekg(0);

        // deserialize the buffer into msgpack::object instance.
        std::string str(buffer.str());

        msgpack::object_handle oh =
            msgpack::unpack(str.data(), str.size());

        // deserialized object is valid during the msgpack::object_handle instance is alive.
        msgpack::object deserialized = oh.get();

        // msgpack::object supports ostream.
        std::cout << deserialized << std::endl;

        // convert msgpack::object instance into the original type.
        // if the type is mismatched, it throws msgpack::type_error exception.
        msgpack::type::tuple<int, bool, std::string> dst;
        deserialized.convert(dst);
    }
    
    
    SECTION("AStar")
    {
		int xDep = 0;
		int yDep = 1;
		int xArr = 5;
		int yArr = 10;
	
		stack<Position> chemin = pathFind(xDep, yDep, xArr, yArr);
		while(!chemin.empty()){
			cout << chemin.top().getX() << ";" << chemin.top().getY() << endl;
			chemin.pop();
		}
    }
    
}
