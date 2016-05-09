#ifndef TOOLS_HPP
#define TOOLS_HPP

/*!
 * \file Tools.hpp
 * \brief contient des fonctions utiles aux Factories (entre autres)
 * \author Groupe IA
 */
 
#include <fstream>
#include <ctime>
#include <iomanip>
#include <limits>
#include <cstdlib>
#include <vector>
#include <map>
#include <iostream>
#include <cstring>

#include "tool/cJSON.hpp"

using namespace std;

/*!
*\brief tirage aléatoire entre dans un intervalle
*\param min : valeur minimum de l'itervalle
*\param max : valeur maximum de l'intervalle (non compris dans l'intervalle)
*/
template<typename T>
T rand(T min, T max) {
	srand (std::time(0) + (int)(rand() * 10));

	return min + (T)rand() / ((T)RAND_MAX / (T)((max) - min));
}

/*!
*\brief tirage aléatoire d'un nom masculin (les noms sont stockés dans un fichier de config)
*/
std::string getRandomMaleName();

/*!
*\brief tirage aléatoire d'un nom féminin (les noms sont stockés dans un fichier de config)
*/
std::string getRandomFemaleName();

/*!
*\brief découpage d'une chaine de caractèrere selon un autre chaine de caractères
*\param str : chaîne à découper
*\param delimiter : séparateur
*/
std::vector<std::string> cutString(std::string & str, std::string delimiter);

template<typename T>
int findInVector(std::vector<T> v, T element) {
	for (size_t i = 0; i < v.size(); ++i) {
		if (v[i] == element) {
			return i;
		}
	}
	return -1;
}

/*!
*\brief map des ressources présentes sur la carte
*\param string : le nom du fichier json de la carte à ouvrir
*/
map<pair<int,int>, char>getResourcesMap(string);

/*!
*\brief map des hauteurs de la carte
*\param string : le nom du fichier json de la carte à ouvrir
*/
map<pair<int,int>, float>getHauteursMap(string);

bool loadAllFiles();

#endif
