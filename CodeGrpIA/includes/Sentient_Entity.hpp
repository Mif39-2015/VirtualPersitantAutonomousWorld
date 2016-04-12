#ifndef SENTIENT_ENTITY_HPP
#define SENTIENT_ENTITY_HPP

#include <string>
#include <map>

#include "Entity.hpp"
//#include "Characteristic.hpp"

class Sentient_Entity : public Entity{
public:
	/*
	* C'est un constructeur avec 2 parametres oú le premier est la
	* position,le deuxieme est le nom de sentient entity concerné
	* et le troisieme son id
	* */
	Sentient_Entity(Position pos, std::string, std::string);
	/*
	* Ce methode renvoie la valeur de la clé id de la map.
	* Si la clé existe, sa valeur associée est renvoyée, sinon -1
	* */
    int getVal(int id);
	/*
	* Ce methode met à jour la valeur associée à la clé id si cette derniere
	* existe bien dans la map et renvoie 1 (success) sinon renvoie -1
	* */
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
