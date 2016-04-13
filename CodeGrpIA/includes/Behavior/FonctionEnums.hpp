#ifndef FONCTION_ENUM_HPP
#define FONCTION_ENUM_HPP

//~ #include "Entity/Sentient_Entity.hpp"
#include "Entity/Entity.hpp"

#include <iostream>
#include <map>

class Sentient_Entity;

using namespace std;

//La nomination des enum est faite ainsi : FONC + type de retour + type de paramètre (s'il y en a un autre que la Sentient_Entity, qui est obligatoire

typedef enum { // Basiquement, ça, c'est les fonction d'action ne prenant pas de paramètres et ne renvoyant rien
	IDLE
	,DORMIR
	,GOTO_HAUT
	,GOTO_BAS
	,GOTO_GAUCHE
	,GOTO_DROITE
	,FONC_V_NULL
} FONC_VOID;

typedef enum { //Des fonction d'action prenant un paramètre spécifique(une Entity) et ne renvoyant rien du tout
	GoTo
	,FONC_V_E_NULL
} FONC_VOID_ENTITY;

typedef enum { //Des fonctions prenant un paramètre spécifique et renvoyant une Entity
	GetHallOf
	,GetNearestOf
	,FONC_E_E_NULL
} FONC_ENTITY_ENTITY;

typedef enum {
	Fonction_BOOL_TRUE
	,Fonction_BOOL_FALSE
	,FONC_B_NULL
} FONC_BOOL;

typedef enum {
	FONC_B_E_NULL
} FONC_BOOl_ENTITY;

typedef enum {
	Fonction_INT_1
	,Fonction_INT_2
	,Fonction_INT_3
	,Fonction_INT_4
	,FONC_I_E_NULL
} FONC_INT_ENTITY;

class MapEnumPointeur {
	public :
		static map<FONC_BOOL			, bool(*)		(Sentient_Entity * a)> mapFoncBool;
		static map<FONC_VOID			, void(*)		(Sentient_Entity * a)> mapFoncVoid;
		static map<FONC_VOID_ENTITY		, void(*)		(Sentient_Entity * a, Entity * e)> mapFoncVoidEntity;
		static map<FONC_INT_ENTITY		, int(*)		(Sentient_Entity * a, Entity * e)> mapFoncIntEntity;
		static map<FONC_ENTITY_ENTITY	, Entity *(*)	(Sentient_Entity * a, Entity * e)> mapFoncEntityEntity;
};

//FONC_BOOL
bool fonction_true(Sentient_Entity * a);
bool fonction_false(Sentient_Entity * a);

//FONC_INT_ENTITY
int fonction_int_1(Sentient_Entity * a, Entity * e);
int fonction_int_2(Sentient_Entity * a, Entity * e);
int fonction_int_3(Sentient_Entity * a, Entity * e);
int fonction_int_4(Sentient_Entity * a, Entity * e);

//FONC_VOID
void idle(Sentient_Entity * agent);
void dormir(Sentient_Entity * agent);
void goto_haut(Sentient_Entity * agent);
void goto_bas(Sentient_Entity * agent);
void goto_gauche(Sentient_Entity * agent);
void goto_droite(Sentient_Entity * agent);

//FONC_VOID_ENTITY
void go_to(Sentient_Entity * agent, Entity * e);

//FONC_ENTITY_ENTITY
Entity * getHallOf(Sentient_Entity * agent, Entity * e);
Entity * getNearesOf(Sentient_Entity * agent, Entity * e);

#endif
