#ifndef FONCTION_ENUM_HPP
#define FONCTION_ENUM_HPP

#include "ia/Entity/Entity.hpp"

#include <iostream>
#include <map>

class Sentient_Entity;

using namespace std;

//La nomination des enum est faite ainsi : FONC + type de retour + type de paramètre (s'il y en a un autre que la Sentient_Entity, qui est obligatoire

typedef enum { //FONC_VOID - Basiquement, ça, c'est les fonction d'action ne prenant pas de paramètres et ne renvoyant rien
	IDLE
	, EAT
	, DORMIR
	, GOTO_HAUT
	, GOTO_BAS
	, GOTO_GAUCHE
	, GOTO_DROITE
	, FONC_FAIM_M5
	, FONC_FAIM_P10
	, FONC_V_NULL
} FONC_VOID;

typedef enum { //FONC_VOID_ENTITY - Des fonction d'action prenant un paramètre spécifique(une Entity) et ne renvoyant rien du tout
	GoTo
	, FONC_V_E_NULL
} FONC_VOID_ENTITY;

typedef enum { //FONC_ENTITY - Des fonctions renvoyant une espèce de template d'Entity, contenant les informations minimum nécessaires pour définir un Arbre, une Ressource, etc...
	GetArbre
	, GetRessource
	, GetPierre
} FONC_ENTITY;

typedef enum { //FONC_ENTITY_ENTITY - Des fonctions prenant un paramètre spécifique et renvoyant une Entity
	GetHallOf
	, GetNearestOf
	, FONC_E_E_NULL
} FONC_ENTITY_ENTITY;

typedef enum { //FONC_BOOL
	Fonction_BOOL_TRUE
	, Fonction_BOOL_FALSE
	, FONC_B_NULL
	, FONC_AG_HUNGRY
	, FONC_AG_TIRED
	, FONC_AG_NOT_HUNGRY_ANYMORE
	, FONC_AG_NOT_TIRED_ANYMORE
} FONC_BOOL;

typedef enum { //FONC_BOOl_ENTITY
	FONC_B_E_NULL
} FONC_BOOl_ENTITY;

typedef enum { //FONC_INT_ENTITY
	Fonc_GetFaim
	, FONC_I_E_NULL
} FONC_INT_ENTITY;

class MapEnumPointeur {
	public :
		static map<FONC_ENTITY			, Entity *(*)	()> mapFoncEntity;
		static map<FONC_BOOL			, bool(*)		(Sentient_Entity * a)> mapFoncBool;
		static map<FONC_VOID			, void(*)		(Sentient_Entity * a)> mapFoncVoid;
		static map<FONC_VOID_ENTITY		, void(*)		(Sentient_Entity * a, Entity * e)> mapFoncVoidEntity;
		static map<FONC_INT_ENTITY		, int(*)		(Sentient_Entity * a, Entity * e)> mapFoncIntEntity;
		static map<FONC_ENTITY_ENTITY	, Entity *(*)	(Sentient_Entity * a, Entity * e)> mapFoncEntityEntity;
};

class MapEnumString {
	public :
		static map<std::string	, FONC_VOID			> mapFoncVoid;
		static map<std::string	, FONC_BOOL			> mapFoncBool;
		static map<std::string	, FONC_VOID_ENTITY	> mapFoncVoidEntity;
		static map<std::string	, FONC_INT_ENTITY	> mapFoncIntEntity;
		static map<std::string	, FONC_ENTITY_ENTITY> mapFoncEntityEntity;
};

//FONC_BOOL
bool fonction_true(Sentient_Entity * a);
bool fonction_false(Sentient_Entity * a);
bool fct_entity_is_hungry(Sentient_Entity * a);
bool fct_entity_is_tired(Sentient_Entity * a);
bool fct_entity_isnt_hungry_anymore(Sentient_Entity * a);
bool fct_entity_isnt_tired_anymore(Sentient_Entity * a);

//FONC_INT_ENTITY
int fonction_getFaim(Sentient_Entity * a, Entity * e);

//FONC_VOID
void idle(Sentient_Entity * agent);
void eat(Sentient_Entity * agent);
void dormir(Sentient_Entity * agent);
void goto_haut(Sentient_Entity * agent);
void goto_bas(Sentient_Entity * agent);
void goto_gauche(Sentient_Entity * agent);
void goto_droite(Sentient_Entity * agent);
void faim_p10(Sentient_Entity * agent);
void faim_m5(Sentient_Entity * agent);

//FONC_VOID_ENTITY
void go_to(Sentient_Entity * agent, Entity * e);

//FONC_ENTITY
Entity * getArbre();
Entity * getRessource();

//FONC_ENTITY_ENTITY
Entity * getHallOf(Sentient_Entity * agent, Entity * e);
Entity * getNearesOf(Sentient_Entity * agent, Entity * e);

#endif
