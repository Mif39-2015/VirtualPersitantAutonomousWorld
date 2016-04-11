#ifndef FUNCTION_CONDITION_HPP
#define FUNCTION_CONDITION_HPP

#include <map>
#include "Entity.hpp"

using namespace std;

typedef enum {
	Fonction_BOOL_TRUE,
	Fonction_BOOL_FALSE
} Fonction_Bool;

typedef enum {
	Fonction_INT_1,
	Fonction_INT_2,
	Fonction_INT_3,
	Fonction_INT_4,
	FONC_NULL
} Fonction_Int;

typedef enum {
	Inf,
	Inf_Eg,
	Eg,
	Sup_Eg,
	Sup,
	OP_NULL
} Operator;

struct struct_condition{
	Fonction_Int fonc;
	Entity * e;
	Operator op;
	int comp;
	Fonction_Int fonc2;
	Entity * e2;
};

class FunctionCondition {
	private :
		static map<Fonction_Bool,bool(*)(Entity * a)> mapFonctionsBool;
		static map<Fonction_Int,int(*)(Entity * a, Entity * e)> mapFonctionsInt;
};



#endif
