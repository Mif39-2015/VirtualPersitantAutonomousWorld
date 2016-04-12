#ifndef SENTIENT_ENTITY_HPP
#define SENTIENT_ENTITY_HPP

#include <string>
#include <map>

#include "Entity.hpp"
//#include "Characteristic.hpp"

class Sentient_Entity : public Entity{

public:

Sentient_Entity(std::string, std::string);
    int getVal(int id);
    int setVal(int id, int v);
    /* stockage des alentours de l'agent par rapport à sa position correspondante
     *  dans la map mémorisation*/
    void vision();

protected:
    //idc int c'est l'id de la caractéristique et val 2eme est l'id de ce cen
    std::map<int, int> charact_correspondence;
    /* map de mémorisation de l'agent : on stocke pour chaque position qu'il 
     * a visionné l'entity présent à cette position à ce moment */
    std::map<Position, Entity> memorisation;

};

#endif
