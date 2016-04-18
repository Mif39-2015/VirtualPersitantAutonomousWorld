#include "tool/characteristic.hpp"

int Characteristic::getId(){
    return this->id;
}

int Characteristic::getMin(){
    return this->vmin;
}

int Characteristic::getMax(){
    return this->vmax;
}

std::string Characteristic::getName(){
    return this->name;
}

std::string Characteristic::getDefinition(){
    return this->definition;
}

int Characteristic::getPrecision(){
    return this->precision;
}

void Characteristic::setId(int i){
    this->id=i;
}

void Characteristic::setMin(int m){
    this->vmin=m;
}

void Characteristic::setMax(int m){
    this->vmax=m;
}

void Characteristic::setName(std::string n){
    this->name=n;
}

void Characteristic::setDefinition(std::string d){
    this->definition=d;
}

void Characteristic::setPrecision(int p){
    this->precision=p;
}

