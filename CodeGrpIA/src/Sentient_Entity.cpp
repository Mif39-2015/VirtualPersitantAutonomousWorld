#include <iostream>
#include "Sentient_Entity.hpp"

Sentient_Entity::Sentient_Entity(int x, int y, std::string n, std::string tid) : Entity(n, tid), posX(x), posY(y){
    id = Entity::idCount;
    Entity::idCount++;
}

int Sentient_Entity::getVal(int id){
    if(charact_correspondence.find(id)==charact_correspondence.end()){
        return -1;
    }
    return charact_correspondence.at(id);
}
int Sentient_Entity::setVal(int id, int v){
    //si la clé n'existe pas on fait rien
    if(charact_correspondence.find(id)==charact_correspondence.end()){
        return -1;
    }
    //sinon on met à jour la valeur de la clé existante

    charact_correspondence.at(id)=v;
    return 1;
}
int Sentient_Entity::getPosX(){
    return posX;
}
int Sentient_Entity::getPosY(){
    return posY;
}

void Sentient_Entity::setPosX(int _x){
    posX=_x;
}
void Sentient_Entity::setPosY(int _y){
    posY=_y;
}
