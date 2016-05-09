#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

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

TEST_CASE("Test_Pathfinding", "[astar]")
{
	SECTION("AStar")
	{
		cout << "AStar" << endl;
		int xDep = 0;
		int yDep = 1;
		int xArr = 2;
		int yArr = 3;
		map<pair<int,int>, char> carte = getResourcesMap(PATH_DATA"/map.json");
		map<pair<int,int>, float> carteH = getHauteursMap(PATH_DATA"/map.json");
		stack<Position> chemin = pathFind(xDep, yDep, xArr, yArr, carte, carteH, 1);
		while (!chemin.empty()) {
			cout << chemin.top().getX() << ";" << chemin.top().getY() << endl;
			chemin.pop();
		}
	}

	SECTION("Memoire chemin agent")
	{
		bool loadResult = loadAllFiles();
		REQUIRE(loadResult);

		map<pair<int,int>, char> carte = getResourcesMap(PATH_DATA"/map.json");
		map<pair<int,int>, float> carteH = getHauteursMap(PATH_DATA"/map.json");
		cout << endl << "Memoire chemin agent" << endl;

		cout << endl << "On crée un agent et on lui set sa pos à 2,2" << endl;
		Sentient_Entity * agent = Factories::createAgent();
		agent->setPos(2,2);

		cout << endl << "On cherche un chemin pour arriver en 63,0, on le stocke dans ses chemins mémorisés et on l'affiche" << endl;
		stack<Position> chemin = agent->pathFindTo(Position(63,0), carte, carteH);
		agent->addCheminMemorise(chemin);
		while (!chemin.empty()) {
			cout << chemin.top().getX() << ";" << chemin.top().getY() << endl;
			chemin.pop();
		}

		cout << endl << "On set la pos de l'agent en 4,4 et on veut lui faire atteindre 6,2 sans recalculer AStar grâce à ses chemins connus" << endl;
		agent->setPos(4,4);
		stack<Position> chemin2 = agent->connaitChemin(Position(6,2));
		while (!chemin2.empty()) {
			cout << chemin2.top().getX() << ";" << chemin2.top().getY() << endl;
			chemin2.pop();
		}

	}
}
