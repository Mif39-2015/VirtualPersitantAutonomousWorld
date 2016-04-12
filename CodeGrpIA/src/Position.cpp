#include <iostream>
#include "Position.hpp"
#include <cmath>

Position::Position(int a, int b) : x(a), y(b){}


Position::~Position(){}


int Position::getX(){
    return x;
}

int Position::getY(){
    return y;
}

bool Position::isInCircle(Position* p, int rayon){
    double dist = sqrt((x-p->getX())*(x-p->getX()) + (y-p->getY())*(y-p->getY()));
    if(dist < rayon)
        return true;
    return false;
}