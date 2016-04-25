#include "ia/Behavior/FonctionEnums.hpp"
#include "ia/Entity/Sentient_Entity.hpp"
#include "ia/Entity/Characteristics.hpp"

map<FONC_VOID, void(*)(Sentient_Entity * a)> MapEnumPointeur::mapFoncVoid = {
	{IDLE, idle}
	, {DORMIR, dormir}
	, {GOTO_HAUT, goto_haut}
	, {GOTO_DROITE, goto_droite}
	, {GOTO_GAUCHE, goto_gauche}
	, {GOTO_BAS, goto_bas}
	, {FONC_FAIM_P10, faim_p10}
	, {FONC_FAIM_M5, faim_m5}
};

map<FONC_VOID_ENTITY, void(*)(Sentient_Entity * a, Entity * e)> MapEnumPointeur::mapFoncVoidEntity = {
	{GoTo, go_to}
};

map<FONC_ENTITY_ENTITY, Entity *(*)(Sentient_Entity * a, Entity * e)> MapEnumPointeur::mapFoncEntityEntity = {
	{GetHallOf, getHallOf},
	{GetNearestOf, getNearesOf}
};

map<FONC_BOOL, bool(*)(Sentient_Entity * a)> MapEnumPointeur::mapFoncBool = {
	{Fonction_BOOL_TRUE, fonction_true}
	, {Fonction_BOOL_FALSE, fonction_false}
	, {FONC_AG_HUNGRY, fct_entity_is_hungry}
	, {FONC_AG_TIRED, fct_entity_is_tired}
	, {FONC_AG_NOT_HUNGRY_ANYMORE, fct_entity_isnt_hungry_anymore}
	, {FONC_AG_NOT_TIRED_ANYMORE, fct_entity_isnt_tired_anymore}
};

map<FONC_INT_ENTITY, int(*)(Sentient_Entity * a, Entity * e)> MapEnumPointeur::mapFoncIntEntity = {
	{Fonc_GetFaim, fonction_getFaim}
};

map<std::string	, FONC_VOID			> MapEnumString::mapFoncVoid = {
	{"idle", IDLE}
	, {"dormir", DORMIR}
	, {"goto_haut", GOTO_HAUT}
	, {"goto_droite", GOTO_DROITE}
	, {"goto_gauche", GOTO_GAUCHE}
	, {"goto_bas", GOTO_BAS}
	, {"faim_p10", FONC_FAIM_P10}
	, {"faim_m5", FONC_FAIM_M5}
};

map<std::string	, FONC_BOOL			> MapEnumString::mapFoncBool = {
	{"bool_true", Fonction_BOOL_TRUE}
	, {"bool_false", Fonction_BOOL_FALSE}
	, {"ag_hungry", FONC_AG_HUNGRY}
	, {"ag_tired", FONC_AG_TIRED}
	, {"ag_not_hungry_anymore", FONC_AG_NOT_HUNGRY_ANYMORE}
	, {"ag_not_tired_anymore", FONC_AG_NOT_TIRED_ANYMORE}
};
map<std::string	, FONC_VOID_ENTITY	> MapEnumString::mapFoncVoidEntity = {
	{"goto", GoTo}
};
map<std::string	, FONC_INT_ENTITY	> MapEnumString::mapFoncIntEntity = {
	{"ag_getfaim", Fonc_GetFaim}
};
map<std::string	, FONC_ENTITY_ENTITY> MapEnumString::mapFoncEntityEntity = {
	{"get_hall_of", GetHallOf},
	{"get_nearest_of", GetNearestOf}
};


//FONC_VOID
void idle(Sentient_Entity * agent) {
	cout << "L'agent IDLE" << endl;
}
void dormir(Sentient_Entity * agent) {}
void goto_haut(Sentient_Entity * agent) {}
void goto_bas(Sentient_Entity * agent) {}
void goto_gauche(Sentient_Entity * agent) {}
void goto_droite(Sentient_Entity * agent) {}

void faim_p10(Sentient_Entity * agent) {
	int i = agent->setVal(5, agent->getVal(5) + 10);
}
void faim_m5(Sentient_Entity * agent) {
	int i = agent->setVal(5, agent->getVal(5) - 5);
}

//FONC_VOID_ENTITY
void go_to(Sentient_Entity * agent, Entity * e) {}

//FONC_ENTITY_ENTITY
Entity * getHallOf(Sentient_Entity * agent, Entity * e) {return NULL;}
Entity * getNearesOf(Sentient_Entity * agent, Entity * e) {return NULL;}

//FONC_BOOL
bool fonction_true(Sentient_Entity * a) {
	cout << " je suis dans la fonction_true() liée à FONCTION_BOOL_TRUE " << endl;
	return true;
}

bool fonction_false(Sentient_Entity * a) {
	cout << " je suis dans la fonction_false() liée à FONCTION_BOOL_FALSE " << endl;
	return false;
}

bool fct_entity_is_hungry(Sentient_Entity * a){
	cout << a->getName() << " a faim !" << endl;
	return a->isHungry() == 1;
}

bool fct_entity_is_tired(Sentient_Entity * a){
	cout << a->getName() << " est fatigué(e) !" << endl;
	return a->isTired()  == 1;
}

bool fct_entity_isnt_hungry_anymore(Sentient_Entity * a){
	cout << a->getName() << " n'a plus faim !" << endl;
	return a->getVal(Characs::C_SATIETY) >= Characteristics::getCharacById(Characs::C_SATIETY)->getMax();
}

bool fct_entity_isnt_tired_anymore(Sentient_Entity * a){
	cout << a->getName() << " n'est plus fatigué(e) !" << endl;
	return a->getVal(Characs::C_STAMINA) >= Characteristics::getCharacById(Characs::C_STAMINA)->getMax();
}

//FONC_INT_ENTITY
int fonction_getFaim(Sentient_Entity * a, Entity * e) {
	cout << "Je suis l'agent " << a->getName() << " et j'ai faim à " << a->getVal(5) << " beaucoup" << endl;
	return a->getVal(5);
}
