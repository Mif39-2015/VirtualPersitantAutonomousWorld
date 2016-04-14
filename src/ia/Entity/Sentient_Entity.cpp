#include <iostream>
#include "Entity/Sentient_Entity.hpp"

Sentient_Entity::Sentient_Entity(Position p, std::map<int, int> charac, std::string n, type tid) : Tangible_Entity(n, tid, charac, p){
    id = Entity::idCount;
    Entity::idCount++;
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

void Sentient_Entity::addToTrace(Comportement * c, Noeud * n){}

void Sentient_Entity::AStar(Entity* tar, vector<vector<int>> map)
{
	this->target = tar;
//	for (int i = 0; i < map.size(); i++)
//	{
//		for (int j = 0; j < map[i].size(); j++)
//		{
//			std::cout<<map[i][j]<<" ";
//		}
//		std::cout<<std::endl;
//	}
    
    	
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

}

//Structure nœud = {
//      x, y: Nombre
//      cout, heuristique: Nombre
//   }
//   depart = Nœud(x=_, y=_, cout=0, heuristique=0)
//   Fonction compare2Noeuds(n1:Nœud, n2:Nœud)
//       si n1.heuristique < n2.heuristique 
//           retourner 1
//       ou si n1.heuristique  == n2.heuristique 
//           retourner 0
//       sinon
//           retourner -1
//   Fonction cheminPlusCourt(g:Graphe, objectif:Nœud, depart:Nœud)
//       closedList = File()
//       openList = FilePrioritaire(comparateur=compare2Noeuds)
//       openList.ajouter(depart)
//       tant que openList n'est pas vide
//           u = openList.depiler()
//           si u.x == objectif.x et u.y == objectif.y
//               reconstituerChemin(u)
//               terminer le programme (sans erreur)
//           sinon
//               pour chaque voisin v de u dans g
//                   si v est une case libre
//                       si v existe dans closedList avec un cout inférieur
//                        ou si v existe dans openList avec un cout inférieur
//                           neRienFaire()
//                       sinon
//                            v.cout = u.cout +1 
//                            v.heuristique = v.cout + distance([v.x, v.y], [objectif.x, objectif.y])
//                            openList.ajouter(v)
//            closedList.ajouter(u)
//       terminer le programme (avec erreur)


