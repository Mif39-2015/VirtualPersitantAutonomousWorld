#include "FonctionAction.hpp"

map<Fonction_Action_Simple, void(*)(Sentient_Entity * a)> FonctionAction::mapFonctionsSimple = {
	{IDLE, idle}
	,{DORMIR, dormir}
	,{GOTO_HAUT, goto_haut}
	,{GOTO_DROITE, goto_droite}
	,{GOTO_GAUCHE, goto_gauche}
	,{GOTO_BAS, goto_bas}
};

map<Fonction_Action_Parametre, void(*)(Sentient_Entity * a, Entity * e)> FonctionAction::mapFonctionsParametre = {
	{GoTo, go_to}
};

map<Fonction_Action_Parametre_Retour, Entity *(*)(Sentient_Entity * a, Entity * e)> FonctionAction::mapFonctionsParametreRetour = {
	{GetHallOf, getHallOf},
	{GetNearestOf, getNearesOf}
};

void idle(Sentient_Entity * agent){
	cout << "L'agent IDLE" << endl;
}

//Fonction_Action_Simple
void dormir(Sentient_Entity * agent){}
void goto_haut(Sentient_Entity * agent){}
void goto_bas(Sentient_Entity * agent){}
void goto_gauche(Sentient_Entity * agent){}
void goto_droite(Sentient_Entity * agent){}

//Fonction_Action_Parametre
void go_to(Sentient_Entity * agent, Entity * e){}

//Fonction_Action_Parametre_Retour
Entity * getHallOf(Sentient_Entity * agent, Entity * e){return NULL;}
Entity * getNearesOf(Sentient_Entity * agent, Entity * e){return NULL;}
