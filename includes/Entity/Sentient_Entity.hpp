#ifndef SENTIENT_ENTITY_HPP
#define SENTIENT_ENTITY_HPP

using namespace std;

#include <string>
#include <map>
#include <stack>
#include <utility>
#include <cmath>

#include "Entity/Tangible_Entity.hpp"
#include "Behavior/Comportement.hpp"
#include "Behavior/EtatEnum.hpp"
class Comportement;
class Noeud;

class Sentient_Entity : public Tangible_Entity{
	protected:
		
		std::map<int, int> charact_correspondence; /*!<un map de correspondance entre la caracteristique et le sentient entity.*/

                ETAT etat_entity  ;

		
		std::map<Position, Entity> memorisation; /*!<map de mémorisation de l'agent : on stocke pour chaque position qu'il a visionné l'entity présent à cette position à ce moment*/


		stack<pair<Comportement *,Noeud *>> trace;
		
		Entity* target; /*!<L'endroit que l'entité souhaite atteindre via le chemin'*/
		
		stack<Position> path; /*!<Le chemin a parcourir pour atteindre la cible'*/

	public:
		/*
		* C'est un constructeur avec 2 parametres oú le premier est la
		* position,le deuxieme est le nom de sentient entity concerné
		* et le troisieme son id
		* */
		Sentient_Entity(Position pos, std::string, type);
		/*
		* Ce methode renvoie la valeur de la clé id de la map.
		* Si la clé existe, sa valeur associée est renvoyée, sinon -1
		* */
		int getVal(int id);
		/*
		* Ce methode met à jour la valeur associée à la clé id si cette derniere
		* existe bien dans la map et renvoie 1 (success) sinon renvoie -1
		* */
		int setVal(int id, int v);
		/* stockage des alentours de l'agent par rapport à sa position correspondante
		 *  dans la map mémorisation*/
		void vision();
		
		/*!
		*\brief Trouve le plus court chemin entre la postion de l'entité et sa cible. Remplit l'attribut Path
		*\param tar : entité à atteindre
		*\param map : carte du monde
		*/
		void AStar(Entity* tar, vector<vector<int>> map);
		
		int compare2Pos(Position p1, Position p2);
		
		int distEucli(Position ar);

		void addToTrace(Comportement * c, Noeud * n);
		void removeTopTrace();
};

#endif
