#include <iostream>
#include "ia/Entity/Insentient_Entity.hpp"

Insentient_Entity::Insentient_Entity(std::string n, type tid,std::map<int, int> charac, int o, int x, int y) : Tangible_Entity(n, tid, charac, Position(x,y)){}

int Insentient_Entity::getValById(int id){
    if(characteristics.find(id)==characteristics.end()){
        return -1;
    }
    return characteristics.at(id);
}
int Insentient_Entity::setValById(int id, int v){
    //si la clé n'existe pas on fait rien
    if(characteristics.find(id)==characteristics.end()){
        return -1;
    }
    //sinon on met à jour la valeur de la clé existante

    characteristics.at(id)=v;
    return 1;
}
