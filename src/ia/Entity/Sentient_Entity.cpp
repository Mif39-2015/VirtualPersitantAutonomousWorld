#include <iostream>
#include "ia/Behavior/Noeud.hpp"
#include "ia/Entity/Sentient_Entity.hpp"

Sentient_Entity::Sentient_Entity(Position p, std::map<int, int> charac, std::string n, type tid) : Tangible_Entity(n, tid, charac, p){}

void Sentient_Entity::vision(){
	int vue = 10;
	for(int x=pos.getX()-vue/2; x<pos.getX()+vue/2; x++){
		for(int y=pos.getY()-vue/2; y<pos.getY()+vue/2; y++){
			Position* newPos = new Position(x,y);
			if(pos.isInCircle(newPos,vue)){
			   //memorisation[newPos] = map.getEntityAt(newPos);
			}
		}
	}
}

int Sentient_Entity::compare2Pos(Position p1, Position p2)
{
	int d1 = this->distEucli(p1);
	int d2 = this->distEucli(p2);

	if (d1<d2)
		return 1;
	else if (d1==d2)
		return 0;
	else
		return -1;
}

int Sentient_Entity::distEucli(Position ar)
{

	return sqrt(pow((this->getPos().getX()-ar.getX()),2) + pow((this->getPos().getY()-ar.getY()),2));
}

void Sentient_Entity::run(){
	//Executer le noeud courant
	//avancer si on peux, ou rester sur le noeud courant
	std::tuple<Comportement *, Noeud *, bool> t = trace.top();
	Noeud * n = std::get<1>(t);
	Noeud * n2;
	n2 = n->executerNoeud( this, !std::get<2>(t));

	if(n2 != n){
		std::get<1>(t) = n2;
		trace.pop();
		trace.push(t);
	}
}

void Sentient_Entity::addToTrace(Comportement * c, Noeud * n, bool b){
	if(!trace.empty()){
		std::tuple<Comportement *, Noeud *, bool> t2 = trace.top();
		std::get<2>(t2) = b;
		trace.pop();
		trace.push(t2);
	}

	std::tuple<Comportement *, Noeud *, bool> t (c, n, false);
	trace.push(t);
}

stack<Position> Sentient_Entity::pathFindTo(Position posTo){
	stack<Position> chemin = pathFind(pos.getX(), pos.getY(), posTo.getX(), posTo.getY());
}

void Sentient_Entity::setCheminMemorise(stack<Position> chemin){
	cheminMemorise = chemin;
}
		
stack<Position> Sentient_Entity::getCheminMemorise(){
	return cheminMemorise;
}

stack<Position> Sentient_Entity::connaitChemin(Position posFinale){
	stack<Position> cheminTemp = cheminMemorise;
	stack<Position> cheminInverse;
	stack<Position> cheminReturn;
	while(!cheminTemp.empty()){
		cheminInverse.push(cheminTemp.top());
		if (cheminTemp.top().getX() == posFinale.getX() && cheminTemp.top().getY() == posFinale.getY() ){
			 while(!cheminInverse.empty()){
				 cheminReturn.push(cheminInverse.top());
				 cheminInverse.pop();
			 }
			 return cheminReturn;
		 }
		cheminTemp.pop();
	}
	return cheminTemp;
}
