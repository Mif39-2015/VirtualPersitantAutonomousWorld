#include "FonctionCondition.hpp"

#include <map>

using namespace std;

map<Fonction_Bool, bool(*)(Sentient_Entity * a)> FonctionCondition::mapFonctionsBool = {
	{Fonction_BOOL_TRUE,fonction_true}
	,{Fonction_BOOL_FALSE,fonction_false}
};

map<Fonction_Int, int(*)(Sentient_Entity * a, Entity * e)> FonctionCondition::mapFonctionsInt = {
	{Fonction_INT_1,fonction_int_1}
	,{Fonction_INT_2,fonction_int_2}
	,{Fonction_INT_3,fonction_int_3}
	,{Fonction_INT_4,fonction_int_4}
};

bool fonction_true(Sentient_Entity * a){
	cout << " je suis dans la fonction_true() liée à FONCTION_BOOL_TRUE " << endl;
	return true;
}

bool fonction_false(Sentient_Entity * a){
	cout << " je suis dans la fonction_false() liée à FONCTION_BOOL_FALSE " << endl;
	return false;
}

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
