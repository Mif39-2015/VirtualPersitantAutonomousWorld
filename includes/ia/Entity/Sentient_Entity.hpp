#ifndef SENTIENT_ENTITY_HPP
#define SENTIENT_ENTITY_HPP

#include <string>
#include <map>
#include <stack>
#include <utility>
#include <cmath>
#include <tuple>
#include <vector>
#include <stack>


#include "ia/Entity/Tangible_Entity.hpp"
#include "ia/Behavior/EtatEnum.hpp"
#include "ia/Tools/Position.hpp"
#include "ia/Tools/Astar.hpp"

class Comportement;
class Noeud;

using namespace std;

class Sentient_Entity : public Tangible_Entity {

protected:

	ETAT etat_entity;
	map<Position, Entity> memorisation; /*!<map de mémorisation de l'agent : on stocke pour chaque position qu'il a visionné l'entity présent à cette position à ce moment*/
	Entity* target; /*!<L'endroit que l'entité souhaite atteindre via le chemin'*/
	map<int, int> charact_correspondence; /*!<un map de correspondance entre la caracteristique et le sentient entity.*/
	stack<Position> path; /*!<Le chemin a parcourir pour atteindre la cible'*/
	stack<std::tuple<Comportement *, Noeud *, bool>> trace;
	vector<stack<Position>> cheminMemorise;/*!<Le chemin pour aller de la position initiale à la position voulue'*/

public:
	/*!
	* \brief constructeur avec 2 parametres oú le premier est la
	* position,le deuxieme est le nom de sentient entity concerné
	* et le troisieme son id
	*/
	Sentient_Entity(Position pos, std::map<int, int> charac, std::string, type);

	/*!
	* \brief Fixe un comportement comp pour la sentient_entity
	* \param comp: pointeur vers le comportement à fixer
	*/
	void setComportement(Comportement * comp);

	/*!
	* \brief stockage des alentours de
	* l'agent par rapport à sa position correspondante
	*  dans la map mémorisation
	*/
	void vision();

	/*!
	* \brief Trouve le plus cours chemin jusqu'à une position
	* \param pos: la position à atteindre
	* \param carte: la carte des ressources
	* \param carteH: la carte des hauteurs
	* \return un stack de Position séparant l'entity de la pos si le chemin existe, un stack vide sinon
	* */
	stack<Position> pathFindTo(Position pos, map<pair<int, int>, char> carte, map<pair<int, int>, float> carteH);

	/*!
	* \brief Compare deux position et sur la base de la proximité avec la position courante
	* retourne 1 si si p1 est plus proche de la position courante que p2
	* retourne 0 si p1 et p2 sont à la même distance de p
	* retourne -1 sinon
	* \return integer
	*/
	int compare2Pos(Position p1, Position p2);

	/*!
	* \brief calcul la distance entre une position et la Position courante
	* \param ar : la position dont on souhaite calculer la distance
	* \return integer
	*/
	int distEucli(Position ar);

	/*!
	* \brief fait avancer l'agent dans son comportement de un tick d'horloge
	*/
	void run(unsigned int wstime);

	/*!
	* \brief change le comportement courant de l'agent en l'ajoutant à sa pile de comportement'
	*/
	void addToTrace(Comportement * c, Noeud * n, bool b);

	/*!
	* \brief change le comportement courant de l'agent en retirant le comportement courant du sommet de la pile
	*/
	void removeTopTrace();

	/*!
	* \brief Modifie les chemins mémorisés par l'agent
	*/
	void setCheminMemorise(vector<stack<Position>>);

	/*!
	* \brief Récupère les chemins mémorisés par l'agent
	*/
	vector<stack<Position>> getCheminMemorise();

	/*!
	* \brief Ajoute un chemin dans la liste des chemins mémorisés par l'agent
	*/
	void addCheminMemorise(stack<Position>);

	/*!
	* \brief un stack de Position séparant l'entity de la pos si le chemin existe, un stack vide sinon
	*/
	stack<Position> connaitChemin(Position);

	cJSON* toJson();

	void affiche();
};

#endif
