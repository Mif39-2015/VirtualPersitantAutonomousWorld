#ifndef ASTAR_HPP
#define ASTAR_HPP

#include <iostream>
#include <queue> 
#include <cmath>
#include <map>
#include <cstdio>
#include <stack>

#include "ia/Tools/Position.hpp"

using namespace std;

class Node;

class Node
{
	private:
    // position courante
    int xPos;
    int yPos;
    // distance totale déjà parcouru pour atteindre le noeud
    float cout;
    // heuristique = cout  + distance restante estimée
    float heuristique;  // plus petite valeur : plus haute priorité
	
    public:
        Node(int, int);
        Node(int, int, int, int);
		
		int px; int py;
        int getxPos() const {return xPos;}
        int getyPos() const {return yPos;}
        float getCout() const {return cout;}
        float getHeuristique() const {return heuristique;}
        
        void setCout(float l) {cout = l;}
		
        void updateHeuristique(const int &, const int &);

       /* // give better priority to going strait instead of diagonally
        void nextLevel(const int & i) // i: direction
        {
             level+=(dir==8?(i%2==0?10:14):10);
        }*/
        
        //  Fonction d'estimation de la distance restante pour atteindre l'arrivée
        const float & estimate(const int &, const int &) const;
};

class CompareNode
{
public:
	// Fonction qui détermine la priorité pour la priority_queue
	bool operator()(const Node & a, const Node & b)
	{
	  return a.getHeuristique() > b.getHeuristique();  
	}
};

stack<Position> pathFind(const int &, const int &, const int &, const int &, map<pair<int,int>,char>, map<pair<int,int>, float>, int maxHauteur);

#endif


