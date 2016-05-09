#ifndef ETATENUM_HPP
#define ETATENUM_HPP

#include "ia/Entity/Entity.hpp"

#include <iostream>
#include <map>

class Sentient_Entity;

using namespace std;

typedef enum {
	  NORD = 0
	, SUD = 1
	, EST = 2
	, OUEST = 3
	, MANGER = 4
	, COUPER_BOIS = 5
	, PRENDRE = 6
	, SAUTER = 7
	, FRAPPER = 8
	, CONSTRUIRE = 9
	, A_FAIM = 10
	, PAS_FAIM = 11
} ETAT;

#endif  /* ETATENUM_HPP */

