#include <iostream>
#include "Entity/Sentient_Entity.hpp"

Sentient_Entity::Sentient_Entity(Position _pos, std::string n, type tid) : Tangible_Entity(n, tid){
    pos = _pos;
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

void Sentient_Entity::vision(){
    int vue = 10;
    for(int x=pos.getX()-vue/2; x<pos.getX()+vue/2; x++){
        for(int y=pos.getY()-vue/2; y<pos.getY()+vue/2; y++){
            Position* newPos = new Position(x,y);
            if(pos.isInCircle(newPos,vue)){
               // memorisation[newPos] = map.getEntityAt(newPos);
            }
        }
    }

}

void Sentient_Entity::addToTrace(Comportement * c, Noeud * n){}
