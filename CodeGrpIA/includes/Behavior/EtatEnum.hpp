#ifndef ETATENUM_HPP
#define	ETATENUM_HPP

#include "Entity/Entity.hpp"

#include <iostream>
#include <map>

class Sentient_Entity;

using namespace std;

typedef enum {
    ETAT_NORD
    ,ETAT_SUD
    ,ETAT_EST
    ,ETAT_OUEST        
    ,ETAT_MANGER
    ,ETAT_DORMIR
    ,ETAT_COUPER_BOIS
    ,ETAT_PRENDRE
    ,ETAT_SAUTER
    ,ETAT_A_FAIM
    ,ETAT_PAS_FAIM
} ETAT;


class MapEnumEtat {
	public :
		static map<ETAT,std::string> mapEnumEtatString;
};

#endif	/* ETATENUM_HPP */

