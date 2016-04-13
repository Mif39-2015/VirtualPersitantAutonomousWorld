#include "Behavior/EtatEnum.hpp"


map<ETAT,std::string> MapEnumEtat::mapEnumEtatString = {
        {ETAT_NORD,"nord"}
    ,{ETAT_SUD,"sud"}
    ,{ETAT_EST,"est"}
    ,{ETAT_OUEST,"ouest"} 
    ,{ETAT_MANGER,"manger"}
    ,{ETAT_COUPER_BOIS,"couper_bois"}
    ,{ETAT_PRENDRE,"prendre"}
    ,{ETAT_SAUTER,"sauter"}
    ,{ETAT_A_FAIM,"a_faim"}
    ,{ETAT_PAS_FAIM,"pas_faim"}
};
