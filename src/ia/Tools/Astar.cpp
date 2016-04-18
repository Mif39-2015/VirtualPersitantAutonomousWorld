#include "ia/Tools/Astar.hpp"

Node::Node(int xp, int yp){
	xPos=xp; 
	yPos=yp;
}
Node::Node(int xp, int yp, int d, int p){
	xPos=xp; 
	yPos=yp; 
	cout=d; 
	heuristique=p;
}

void Node::updateHeuristique(const int & xDest, const int & yDest)
{
	 heuristique = cout + estimate(xDest, yDest)*10;
}

const float & Node::estimate(const int & xDest, const int & yDest) const
{
	static int xd, yd;
	static float d;
	xd=xDest-xPos;
	yd=yDest-yPos;         

	// Distance euclidienne
	d=sqrt(xd*xd+yd*yd);
	return(d);
}


bool operator==(Node const& a, Node const& b)
{
    if(a.getxPos() == b.getxPos() && a.getyPos() == b.getyPos())
		return true;
    return false;
}

bool operator<(Node const &a, Node const& b)
{
    if(a.getCout() < b.getCout())
		return true;
    return false;	
}

stack<Position> pathFind(const int & xDepart, const int & yDepart, 
                const int & xArrivee, const int & yArrivee, map<pair<int,int>, char> carte)
{	
	map<Node, int> closedList;			
	priority_queue<Node, vector<Node>, CompareNode> openList;
	
	// vector copie de la priority_queue pour pouvoir itérer dessus
	vector<Node> saveOpenList;  
	
	Node depart = Node(xDepart, yDepart, 0, 0);
	openList.push(depart);
	saveOpenList.push_back(depart);
	
	stack<Position> cheminStack;
	// tant que openList n'est pas vide
	while(!openList.empty()){
		Node u = openList.top();
		for(std::vector<Node>::iterator  it = saveOpenList.begin(); it != saveOpenList.end(); ++it) {
			if((*it) == u){
				saveOpenList.erase(it);
				break;
			}
		}
		openList.pop();
		// si la case correspond à la case d'arrivée
		if(u.getxPos() == xArrivee && u.getyPos() == yArrivee){
			// Reconstruction du chemin et fin de l'algo avec succès
			Node chemin = u;
			bool continuer = true;
			while(continuer){
				if(chemin.px == xDepart && chemin.py == yDepart)
					continuer = false;
					
				cheminStack.push(Position(chemin.getxPos(), chemin.getyPos()));	
							
				map<Node, int>::iterator p;
				for(p = closedList.begin(); p != closedList.end(); p++){	
					if(Node(chemin.px, chemin.py) == (p->first)){
						chemin = p->first;
					}
				}	
			}
			cheminStack.push(Position(chemin.getxPos(), chemin.getyPos()));	
			return cheminStack;			
		}
		else{
			for(int x=u.getxPos()-1 ; x<=u.getxPos()+1 ; x++){
				for(int y=u.getyPos()-1 ; y<=u.getyPos()+1 ; y++){
					bool nerienfaire = false;
					if(x != u.getxPos() || y != u.getyPos()) // On vérifie que ce n'est pas la même case
					{
						Node v = Node(x,y);
						map<Node, int>::iterator p;
						// si v est une case libre
						if(carte[make_pair(x,y)] == '0'){
							// si v est dans la closedList avec un cout inférieur 
							for(p = closedList.begin(); p != closedList.end(); p++){
								if(p->first == v && p->second < u.getCout()){
									nerienfaire = true;
								}					
							}
							if(p->second < u.getCout()){
								// ou si v existe dans openList avec un cout inférieur
								for(std::vector<Node>::iterator  it = saveOpenList.begin(); it != saveOpenList.end(); ++it) {
									if((*it) == v && (*it).getCout() < u.getCout()){
										 nerienfaire = true;
									}		
								}
							}
							if(!nerienfaire){
								if(x == u.getxPos() || y == u.getyPos())
									v.setCout(u.getCout() +1); // cout de 1 si case adjacente 
								else
									v.setCout(u.getCout() + sqrt(2)); // cout de sqrt(2) sinon
								v.updateHeuristique(xArrivee, yArrivee);
								v.px = u.getxPos();
								v.py = u.getyPos();
								
								openList.push(v);
								saveOpenList.push_back(v);
							}		
						}	
					}
				}			
			}
		}
		closedList.emplace(u, u.getCout());
	}
	
	return cheminStack;
}






