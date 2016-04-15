#ifndef ETATENUM_HPP
#define ETATENUM_HPP

#include "Entity/Entity.hpp"

#include <iostream>
#include <map>

class Sentient_Entity;

using namespace std;

typedef enum {
	NORD
	, SUD
	, EST
	, OUEST
	, MANGER
	, COUPER_BOIS
	, PRENDRE
	, SAUTER
	, FRAPPER
	, CONSTRUIRE
	, A_FAIM
	, PAS_FAIM
} ETAT;

#endif  /* ETATENUM_HPP */

