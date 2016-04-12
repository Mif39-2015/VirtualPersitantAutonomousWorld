#ifndef FONCTION_CONDITION_HPP
#define FONCTION_CONDITION_HPP

using namespace std;

#include <iostream>
#include <map>

#include "Entity.hpp"

class Sentient_Entity;

typedef enum {
	Fonction_BOOL_TRUE
	,Fonction_BOOL_FALSE
} Fonction_Bool;

typedef enum {
	Fonction_INT_1
	,Fonction_INT_2
	,Fonction_INT_3
	,Fonction_INT_4
	,FONC_NULL
} Fonction_Int;

class FonctionCondition {
	public :
		static map<Fonction_Bool,bool(*)(Sentient_Entity * a)> mapFonctionsBool;
		static map<Fonction_Int,int(*)(Sentient_Entity * a, Entity * e)> mapFonctionsInt;
};

typedef enum {
	Inf
	,Inf_Eg
	,Eg
	,Sup_Eg
	,Sup
	,OP_NULL
} Operator;

struct struct_condition{
	Fonction_Int fonc1;
	Entity * e1;
	Operator op;
	Fonction_Int fonc2;
	Entity * e2;
	int comp;
};

bool fonction_true(Sentient_Entity * a);
bool fonction_false(Sentient_Entity * a);

int fonction_int_1(Sentient_Entity * a, Entity * e);
int fonction_int_2(Sentient_Entity * a, Entity * e);
int fonction_int_3(Sentient_Entity * a, Entity * e);
int fonction_int_4(Sentient_Entity * a, Entity * e);

#endif
