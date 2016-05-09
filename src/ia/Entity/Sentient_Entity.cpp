#include <iostream>
#include "ia/Behavior/Noeud.hpp"
#include "ia/Entity/Sentient_Entity.hpp"
#include "ia/Behavior/Comportement.hpp"
#include "ia/Behavior/EtatEnum.hpp"
#include "ia/Tools/Factories.hpp"

Sentient_Entity::Sentient_Entity(Position p, std::map<int, int> charac, std::string n, type tid) : Tangible_Entity(n, tid, charac, p){
	etat_entity = ETAT::NORD;
	target = nullptr;
}

void Sentient_Entity::setComportement(Comportement * comp) {
    addToTrace(comp, comp->getNoeudDepart(), false);
}

void Sentient_Entity::vision() {
    int vue = 10;
    for (int x = pos.getX() - vue / 2; x < pos.getX() + vue / 2; x++) {
        for (int y = pos.getY() - vue / 2; y < pos.getY() + vue / 2; y++) {
            Position* newPos = new Position(x, y);
            if (pos.isInCircle(newPos, vue)) {
                //memorisation[newPos] = map.getEntityAt(newPos);
            }
        }
    }
}

int Sentient_Entity::compare2Pos(Position p1, Position p2)
{
    int d1 = this->distEucli(p1);
    int d2 = this->distEucli(p2);

    if (d1 < d2)
        return 1;
    else if (d1 == d2)
        return 0;
    else
        return -1;
}

int Sentient_Entity::distEucli(Position ar)
{

    return sqrt(pow((this->getPos().getX() - ar.getX()), 2) + pow((this->getPos().getY() - ar.getY()), 2));
}

void Sentient_Entity::run(unsigned int wstime) {
    //On fait évoluer l'état de l'agent grace à decade()
    this->decade(wstime);

    //Executer le noeud courant
    //avancer si on peux, ou rester sur le noeud courant
    std::tuple<Comportement *, Noeud *, bool> t = trace.top();
    Noeud * n = std::get<1>(t);
    Noeud * n2;
    n2 = n->executerNoeud( this, !std::get<2>(t));
    if (n2 != n) {
        std::get<1>(t) = n2;
        trace.pop();
        trace.push(t);
    }
}

void Sentient_Entity::addToTrace(Comportement * c, Noeud * n, bool b) {
    if (!trace.empty()) {
        std::tuple<Comportement *, Noeud *, bool> t2 = trace.top();
        std::get<2>(t2) = b;
        trace.pop();
        trace.push(t2);
    }

    std::tuple<Comportement *, Noeud *, bool> t (c, n, false);
    trace.push(t);
}

stack<Position> Sentient_Entity::pathFindTo(Position posTo, map<pair<int,int>, char> carte, map<pair<int,int>, float> carteH){
	float maxHauteur = (float) getVal(C_FITNESS) / 100;
	cout << getVal(C_FITNESS) << endl;
	cout << maxHauteur << endl;
    stack<Position> chemin = pathFind(pos.getX(), pos.getY(), posTo.getX(), posTo.getY(), carte, carteH, maxHauteur);
    
    return chemin;
}

void Sentient_Entity::setCheminMemorise(vector<stack<Position>> chemin) {
    cheminMemorise = chemin;
}

vector<stack<Position>> Sentient_Entity::getCheminMemorise() {
    return cheminMemorise;
}

void Sentient_Entity::addCheminMemorise(stack<Position> ch) {
    cheminMemorise.push_back(ch);
}

stack<Position> Sentient_Entity::connaitChemin(Position posFinale) {
    stack<Position> cheminTemp;
    for (vector<stack<Position>>::iterator it = cheminMemorise.begin() ; it != cheminMemorise.end(); ++it) {
        bool findStart = false;
        cheminTemp = *it;
        stack<Position> cheminInverse;
        stack<Position> cheminReturn;
        while (!cheminTemp.empty()) {
            if (cheminTemp.top().getX() == pos.getX() && cheminTemp.top().getY() == pos.getY()) {
                findStart = true;
            }
            if (findStart) {
                cheminInverse.push(cheminTemp.top());
                if (cheminTemp.top().getX() == posFinale.getX() && cheminTemp.top().getY() == posFinale.getY()) {
                    while (!cheminInverse.empty()) {
                        cheminReturn.push(cheminInverse.top());
                        cheminInverse.pop();
                    }
                    return cheminReturn;
                }
            }
            cheminTemp.pop();
        }
    }
    return cheminTemp;
}

cJSON* Sentient_Entity:: toJson() {
    cJSON * tangible_entity = Tangible_Entity::toJson();
    
    cJSON_AddNumberToObject(tangible_entity, "etat", etat_entity);
    
    if (target != nullptr)
    	cJSON_AddNumberToObject(tangible_entity, "cible", target->getId());
    
    return tangible_entity;
}

void Sentient_Entity::affiche()
{
    std::cout << "id : " << id << " name : " << name << std::endl;
}

int Sentient_Entity::getInventoryWeight() {
    int res = 0;
    for (auto it = stock.begin(); it != stock.end(); it++) {
        int add = it->first->getVal(C_WEIGHT);
        if (add != -1)
            res += add * it->second;
    }
    return res;
}

//La récolte des ressources n'est pas optimiser. TODO Optimisation
int Sentient_Entity::removeQuantityAndAddToAgent(Insentient_Entity * resource, Item * i, int qtt) {
    /*if ((getInventoryWeight() + (i->getVal(C_WEIGHT)*qtt)) >= getVal(C_CAPACITY) && qtt > 1) {
        // removeQuantityAndAddToAgent(resource, i, qtt - 1);
    }
    else */if ((getInventoryWeight() + (i->getVal(C_WEIGHT)*qtt)) >= getVal(C_CAPACITY) /*&& qtt <= 1*/) {
        return -2;
    }

    if (resource->getQuantityByItem(i) >= qtt) {
        resource->removeItemFromStock(i, qtt);
        this->addItemToStock(i, qtt);
        return 0;
    }
    else if (resource->getQuantityByItem(i) > 0 && resource->getQuantityByItem(i) < qtt) {
        int q = resource->getQuantityByItem(i);
        resource->removeItemFromStock(i, q);
        this->addItemToStock(i, q);
        return 0;
    }
    return -1;
}

int Sentient_Entity::harvestResource(Insentient_Entity * resource, int qtt) {
    if (resource->getTypeId() == ID_RESSOURCE_BOIS) {
        Item * i = Item::getItemByName("Bois");
        return this->removeQuantityAndAddToAgent(resource, i, qtt);
    }
    else if (resource->getTypeId() == ID_RESSOURCE_PIERRE) {
        Item * i = Item::getItemByName("Pierre");
        return this->removeQuantityAndAddToAgent(resource, i, qtt);
    }
    else if (resource->getTypeId() == ID_RESSOURCE_METAL) {
        Item * i = Item::getItemByName("Metal");
        return this->removeQuantityAndAddToAgent(resource, i, qtt);
    }
    else if (resource->getTypeId() == ID_RESSOURCE_VIANDE) {
        Item * i = Item::getItemByName("Viande");
        return this->removeQuantityAndAddToAgent(resource, i, qtt);
    }
    else if (resource->getTypeId() == ID_RESSOURCE_LEGUME) {
        Item * i = Item::getItemByName("Legume");
        return this->removeQuantityAndAddToAgent(resource, i, qtt);
    }
    return -3;
}
