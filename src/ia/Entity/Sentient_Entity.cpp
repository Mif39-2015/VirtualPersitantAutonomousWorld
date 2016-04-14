#include <iostream>
#include "Entity/Sentient_Entity.hpp"

Sentient_Entity::Sentient_Entity(Position p, std::string n, type tid) : Tangible_Entity(n, tid, p){
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
			   //memorisation[newPos] = map.getEntityAt(newPos);
			}
		}
	}

}

void Sentient_Entity::run(){
	//Executer le noeud courant
	//avancer si on peux, ou rester sur le noeud courant
	std::tuple<Comportement *, Noeud *, bool> t = trace.top();
	Noeud * n = std::get<1>(t);
	Noeud * n2;
	// n2 = n->executerNoeud(*this, !std::get<2>(t));

	if(n2 != n){
		std::get<1>(t) = n2;
		trace.pop();
		trace.push(t);
	}
}

void Sentient_Entity::addToTrace(Comportement * c, Noeud * n, bool b){
	std::tuple<Comportement *, Noeud *, bool> t2 = trace.top();
	std::get<2>(t2) = b;
	trace.pop();
	trace.push(t2);

	std::tuple<Comportement *, Noeud *, bool> t (c, n, false);
	trace.push(t);
}
