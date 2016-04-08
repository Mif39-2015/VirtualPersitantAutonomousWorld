#include <iostream>
#include "Tribe.hpp"

Tribe::Tribe(unsigned int i, std::string n, unsigned int gi) : id(i), name(n), goal_index(gi) {}

/*getters*/
unsigned int Tribe::getId(){
    return id;
}
std::string Tribe::getName(){
    return name;
}
unsigned int Tribe::getGoalIndex(){
    return goal_index;
}

/*setters*/
void Tribe::setId(unsigned int _id){
    id=_id;
}
void Tribe::setName(std::string _n){
    name=_n;
}
void Tribe::setGoalIndex(unsigned int _goal_index){
    goal_index=_goal_index;
}
int Tribe::getTribeSize(){
    int sizet=0;
    for(std::vector<Agent>it = population.begin(); it!=population.end(); it++){
        sizet++;
    }
    return sizet;
}
void Tribe::welcomeNewMember(Agent a){
    population.push_back(a);
}
int Tribe::getQuantityByItem(Item i){
    return stock.at(i);
}
void Tribe::addItemToStock(Item i, int quantity){
    if(stock.find(i)==stock.end())
        stock.insert(std::pair<Item, int>(i, quantity));
    else
        stock.at(i)=stock.find(i)->second+quantity;
}
