#ifndef SENTIENT_ENTITY_HPP
#define SENTIENT_ENTITY_HPP

#include <string>
#include <map>

#include "Entity.hpp"
//#include "Characteristic.hpp"

class Sentient_Entity : public Entity{

public:

	/*
	* C'est un constructeur avec 3 parametres oú le premier entier c'est la
	* position de X, le deuxieme c'est la position Y et le troisime c'est
	* le nom de sentient entity concerné
	* */	
	Sentient_Entity(int, int, std::string, std::string);
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
	/*
	* Ce methode renvoie la position X du sentient entity
	* */
    int getPosX();
	/*
	* Ce methode renvoie la postion Y du sentient entity
	* */
    int getPosY();
	/*
	* Ce methode met la valeur de la position de X du sentient entity
	* */
    void setPosX(int _x);
	/*
	* Ce methode met la valeur de la postion de Y du sentient entity
	* */
    void setPosY(int _y);

protected:
	/*
	* Cet attribut represente la postion de X du sentient entity
	* */
    int posX;
	/*
	* Cet attribut represente la position de Y du sentient entity
	* */
    int posY;
    /*
     * Cet attribut represente un map de correspondance entre la caracteristique et le sentient
     * entity. 
     * */
    std::map<int, int> charact_correspondence;


};

#endif
