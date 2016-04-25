#include <cmath>

#include "ia/Tools/Position.hpp"

Position::Position(int a, int b) : x(a), y(b) {}

Position::Position(const Position & p) {
	x = p.getX();
	y = p.getY();
}

Position::~Position() {}


int Position::getX() const {
	return x;
}

int Position::getY() const {
	return y;
}

bool Position::isInCircle(Position * p, int rayon) {
	double dist = sqrt((x - p->getX()) * (x - p->getX()) + (y - p->getY()) * (y - p->getY()));
	if (dist < rayon)
		return true;
	return false;
}

bool Position::operator<(Position const &p2) const
{
    if(getX() < p2.getX())
		return true;
	else if(getY() < p2.getY())
		return true;	
    return false;	
}

//cJSON* Position::toJson()
//{
//	cJSON* pos = cJSON_CreateObject();
//	
//	cJSON_AddNumberToObject(pos, "x", x);
//	cJSON_AddNumberToObject(pos, "y", y);
//	
//	return pos;
//}

