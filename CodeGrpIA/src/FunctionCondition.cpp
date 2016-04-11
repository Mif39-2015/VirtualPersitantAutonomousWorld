#include "FunctionCondition.hpp"

#include <map>

using namespace std;

map<Fonction_Bool, bool(*)(Sentient_Entity * a)> FunctionCondition::mapFonctionsBool = {
	{Fonction_BOOL_TRUE,fonction_true},
	{Fonction_BOOL_FALSE,fonction_false}
};
map<Fonction_Int, int(*)(Sentient_Entity * a, Entity * e)> FunctionCondition::mapFonctionsInt = {

};

bool fonction_true(Sentient_Entity * a){
	cout << " je suis dans la fonction_true() liée à FONCTION_BOOL_TRUE " << endl;
	return true;
}

bool fonction_false(Sentient_Entity * a){
	cout << " je suis dans la fonction_false() liée à FONCTION_BOOL_FALSE " << endl;
	return false;
}
