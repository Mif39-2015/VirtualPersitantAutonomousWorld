#include "Behavior/FonctionEnums.hpp"
#include "Entity/Sentient_Entity.hpp"

map<FONC_VOID, void(*)(Sentient_Entity * a)> MapEnumPointeur::mapFoncVoid = {
	{IDLE, idle}
	,{DORMIR, dormir}
	,{GOTO_HAUT, goto_haut}
	,{GOTO_DROITE, goto_droite}
	,{GOTO_GAUCHE, goto_gauche}
	,{GOTO_BAS, goto_bas}
	,{FONC_FAIM_P10, faim_p10}
	,{FONC_FAIM_M5, faim_m5}
};

map<FONC_VOID_ENTITY, void(*)(Sentient_Entity * a, Entity * e)> MapEnumPointeur::mapFoncVoidEntity = {
	{GoTo, go_to}
};

map<FONC_ENTITY_ENTITY, Entity *(*)(Sentient_Entity * a, Entity * e)> MapEnumPointeur::mapFoncEntityEntity = {
	{GetHallOf, getHallOf},
	{GetNearestOf, getNearesOf}
};

map<FONC_BOOL, bool(*)(Sentient_Entity * a)> MapEnumPointeur::mapFoncBool = {
	{Fonction_BOOL_TRUE,fonction_true}
	,{Fonction_BOOL_FALSE,fonction_false}
};

map<FONC_INT_ENTITY, int(*)(Sentient_Entity * a, Entity * e)> MapEnumPointeur::mapFoncIntEntity = {
	{Fonction_INT_1,fonction_int_1}
	,{Fonction_INT_2,fonction_int_2}
	,{Fonction_INT_3,fonction_int_3}
	,{Fonction_INT_4,fonction_int_4}
};


//FONC_VOID
void idle(Sentient_Entity * agent){
	cout << "L'agent IDLE" << endl;
}
void dormir(Sentient_Entity * agent){}
void goto_haut(Sentient_Entity * agent){}
void goto_bas(Sentient_Entity * agent){}
void goto_gauche(Sentient_Entity * agent){}
void goto_droite(Sentient_Entity * agent){}

void faim_p10(Sentient_Entity * agent){
	agent->setVal(5, agent->getVal(5) + 10);
}
void faim_m5(Sentient_Entity * agent){
	agent->setVal(5, agent->getVal(5) - 5);
}

//FONC_VOID_ENTITY
void go_to(Sentient_Entity * agent, Entity * e){}

//FONC_ENTITY_ENTITY
Entity * getHallOf(Sentient_Entity * agent, Entity * e){return NULL;}
Entity * getNearesOf(Sentient_Entity * agent, Entity * e){return NULL;}

//FONC_BOOL
bool fonction_true(Sentient_Entity * a){
	cout << " je suis dans la fonction_true() liée à FONCTION_BOOL_TRUE " << endl;
	return true;
}

bool fonction_false(Sentient_Entity * a){
	cout << " je suis dans la fonction_false() liée à FONCTION_BOOL_FALSE " << endl;
	return false;
}

//FONC_INT_ENTITY
int fonction_int_1(Sentient_Entity * a, Entity * e){
	cout << "je suis dans la fonction_int_1 liée à FONCTION_INT_1"<<endl;
	return 1;
}

int fonction_int_2(Sentient_Entity * a, Entity * e){
	cout << "je suis dans la fonction_int_2 liée à FONCTION_INT_2"<<endl;
	return 2;
}

int fonction_int_3(Sentient_Entity * a, Entity * e){
	cout << "je suis dans la fonction_int_3 liée à FONCTION_INT_3"<<endl;
	return 3;
}

int fonction_int_4(Sentient_Entity * a, Entity * e){
	cout << "je suis dans la fonction_int_4 liée à FONCTION_INT_4"<<endl;
	return 4;
}
