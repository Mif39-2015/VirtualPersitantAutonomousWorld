
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

TEST_CASE("Test_Comportement", "[comp]")
{
	SECTION("TEST COMPORTEMENT")
	{

		int loadResult = Characteristics::loadCharacteristicsFile(PATH_DATA"/descriptionCharacteristics.json");
		int loadResult2 = Comportement::initVectorComp(PATH_DATA"/foo.json");

		REQUIRE(loadResult  != -1);
		REQUIRE(loadResult2 != -1);

		cout << "ICI, ON TESTE LE COMPORTEMENT" << endl;

		Comportement * c =  new Comportement();

		Noeud * noeudFaimM5 = new Noeud();
		Noeud * noeudFaimP10 = new Noeud();

		Arete * areteFaim20 = new Arete(noeudFaimM5, noeudFaimP10);
		Arete * areteFaim80 = new Arete(noeudFaimP10, noeudFaimM5);

		cout << "declaration des Aretes" << endl;

        noeudFaimM5->ajouterAreteOut(areteFaim20);
        noeudFaimM5->ajouterAreteIn(areteFaim80);
        noeudFaimP10->ajouterAreteIn(areteFaim20);
        noeudFaimP10->ajouterAreteOut(areteFaim80);

		ActionSimple * actionFaimM5 = new ActionSimple();
		ActionSimple * actionFaimP10 = new ActionSimple();

		actionFaimM5->setFonc_Void(FONC_FAIM_M5);
		actionFaimP10->setFonc_Void(FONC_FAIM_P10);

		cout << "Setup des Actions" << endl;

		noeudFaimM5->setAction(actionFaimM5);
		noeudFaimP10->setAction(actionFaimP10);

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

		areteFaim20->setCondition_Complexe(vecStructCondFaim20);

		cout << "on a mis le vecteur dans l'arete" << endl;

		vector<struct_condition> vecStructCondFaim80;
		struct_condition condFaim80;
		condFaim80.fIE1 = Fonc_GetFaim;
		condFaim80.e1 = nullptr;
		condFaim80.op = Sup;
		condFaim80.comp = 80;
		condFaim80.fIE2 = FONC_I_E_NULL;
		vecStructCondFaim80.push_back(condFaim80);
		areteFaim80->setCondition_Complexe(vecStructCondFaim80);

		cout << "pareil pour l'autre arete " << endl;

		c->ajouterNoeud(noeudFaimM5);
		c->ajouterNoeud(noeudFaimP10);

		cout << "on ajoute les noeuds dans le comportement " << endl;

		Sentient_Entity * agent = Factories::createAgent();

		cout << "on a créé l'agent " << endl;

		cout << "on a ajouté le comportement dans l'agent" << endl;

		for (int i = 0; i < 100; ++i) {
			cout << endl << "##### iteration " << i << " : " << endl;
			agent->run();
		}

		delete c;
		delete noeudFaimM5;
		delete noeudFaimP10;
		delete areteFaim80;
		delete areteFaim20;
		delete actionFaimP10;
		delete actionFaimM5;

		std::cout << std::endl;
	}

	SECTION("TEST LISTE COMPORTEMENT")
	{

		std::cout << "TEST LISTE COMPORTEMENT" << std::endl;
		int loadResult = Characteristics::loadCharacteristicsFile(PATH_DATA"/descriptionCharacteristics.json");
		int loadResult2 = Comportement::initVectorComp(PATH_DATA"/foo.json");

		REQUIRE(loadResult  != -1);
		REQUIRE(loadResult2 != -1);

		Sentient_Entity * agent = Factories::createAgent();

		int i = 0;
		while(i < 50){
			agent->run();
			i++;
		}

		std::cout << std::endl;
	}
}


