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
		int xDep = 17;
		int yDep = 7;
		int xArr = 5;
		int yArr = 24;
		map<pair<int,int>, char> carte = getMap("map.txt");
		stack<Position> chemin = pathFind(xDep, yDep, xArr, yArr, carte);
		while (!chemin.empty()) {
			cout << chemin.top().getX() << ";" << chemin.top().getY() << endl;
			chemin.pop();
		}
	}

	SECTION("Memoire chemin agent")
	{
		map<pair<int,int>, char> carte = getMap("map.txt");
		cout << endl << "Memoire chemin agent" << endl;
		
		cout << endl << "On crée un agent et on lui set sa poos à 4,4" << endl;
		Sentient_Entity * agent = Factories::createAgent();
		agent->setPos(4,4);

		cout << endl << "On cherche un chemin pour arriver en 15,20, on le stocke dans ses chemins mémorisés et on l'affiche" << endl;
		stack<Position> chemin = pathFind(agent->getPos().getX(), agent->getPos().getY(),15,20, carte);
		agent->addCheminMemorise(chemin);
		while (!chemin.empty()) {
			cout << chemin.top().getX() << ";" << chemin.top().getY() << endl;
			chemin.pop();
		}
		
		cout << endl << "On set la pos de l'agent en 10,10 et on veut lui faire atteindre 15,18 sans recalculer AStar grâce à ses chemins connus" << endl;	
		agent->setPos(10,12);
		stack<Position> chemin2 = agent->connaitChemin(Position(15,18));
		while (!chemin2.empty()) {
			cout << chemin2.top().getX() << ";" << chemin2.top().getY() << endl;
			chemin2.pop();
		}		
		
	}
	
	SECTION("Map")
	{
		cout << endl << "On récupere la map" << endl;	
		ifstream fichier("map.txt", ios::in);  // on ouvre	
		string ligne;
		map<pair<int,int>, char> carte;
		int l = 0;
		if(fichier)
		{			      
			while(getline(fichier, ligne))  // tant que l'on peut mettre la ligne dans "contenu"
			{
				for(unsigned int i = 0; i < ligne.size(); i++)
				{   
					char caractere = ligne.at(i);// notre variable où sera stocké le caractère
					carte[make_pair(i,l)] = caractere;
					cout << carte[make_pair(i,l)];
					
				}
				l++;
				cout << endl;
			}
			fichier.close();
		}
		else
			cerr << "Impossible d'ouvrir le fichier !" << endl;
	}

}
