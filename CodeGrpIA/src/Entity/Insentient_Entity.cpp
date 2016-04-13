#include <iostream>
#include "Entity/Insentient_Entity.hpp"

unsigned int Insentient_Entity::idCount = 0;

Insentient_Entity::Insentient_Entity(std::string n, type tid, int o, int x, int y, int z) : Tangible_Entity(n, tid),
    orientation(o){
        sizeIE.x=x;
        sizeIE.y=y;
        sizeIE.z=z;
        id = Entity::idCount;
        Entity::idCount++;
}
 int Insentient_Entity::getOrientation(){
    return this->orientation;
 }
void Insentient_Entity::setOrientation(int _o){
    this->orientation=_o;
}
unsigned int Insentient_Entity::getStructuralPoint(){
    return this->structural_point;
}
void Insentient_Entity::setStructuralPoint(unsigned int sp){
    this->structural_point=sp;
}
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
