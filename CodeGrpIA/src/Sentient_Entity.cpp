#include <iostream>
#include "Sentient_Entity.hpp"

Sentient_Entity::Sentient_Entity(int x,  int y, std::string n) : Entity(n), posX(x), posY(y){}

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

//int Sentient_Entity::getVitality(){
//    return vitality;
//}
//bool Sentient_Entity::getGender(){
//    return gender;
//}
//int Sentient_Entity::getAge(){
//    return age;
//}
//int Sentient_Entity::getAgressiveness(){
//    return agressiveness;
//}
//int Sentient_Entity::getFitness(){
//    return fitness;
//}
//int Sentient_Entity::getSatiety(){
//    return satiety;
//}
//int Sentient_Entity::getSatietyTreshold(){
//    return satiety_threshold;
//}
//int Sentient_Entity::getReflex(){
//    return reflex;
//
//}
//int Sentient_Entity::getPerception(){
//    return perception;
//}
//
//void Sentient_Entity::setVitality(int v){
//    vitality=v;
//}
//void Sentient_Entity::setGender(bool g){
//    gender=g;
//}
//void Sentient_Entity::setAge(int a){
//    age=a;
//}
//void Sentient_Entity::setFitness(int f){
//    fitness=f;
//}
//void Sentient_Entity::setAgressiveness(int ag){
//    agressiveness=ag;
//}
//void Sentient_Entity::setSatiety(int s){
//    satiety=s;
//}
//void Sentient_Entity::setSatietyTreshold(int st){
//    satiety_threshold=st;
//}
//void Sentient_Entity::setReflex(int r){
//    reflex=r;
//}
//void Sentient_Entity::setPerception(int p){
//    perception=p;
//}
//
//bool Sentient_Entity::isHungry(){
//    if(satiety==satiety_threshold)
//        return true;
//    return false;
//}
//bool Sentient_Entity::isAgressive(){
//    if(agressiveness>50)
//        return true;
//    return false;
//}
