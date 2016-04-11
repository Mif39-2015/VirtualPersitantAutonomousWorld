#ifndef FUNCTION_CONDITION_HPP
#define FUNCTION_CONDITION_HPP

#include <map>
#include "Agent.hpp"
using namespace std;

typedef enum {
	Fonction_1,
	Fonction_2
} Fonction_Bool;

typedef enum {
	Distance_To,
	How_Much_In_Inventory,
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
		static map<Fonction_Bool,bool(*)(Agent * a)> mapFonctionsBool;
		static map<Fonction_Int,int(*)(Agent * a, Entity * e)> mapFonctionsInt;
};
//~
//~ bool function1(Agent * a, Fonction_Int fI = FONC_NULL, Entity * e = nullptr, Operator op = OP_NULL, int Comp=-1);
//~ bool function2(Agent * a, ...);
//~ int Distance_To(Agent * a, Entity  * e){
	//~ return a->distanceTo(e);
//~ }

#endif
