#ifndef SENTIENT_ENTITY_HPP
#define SENTIENT_ENTITY_HPP

#include <string>
#include <map>
#include <stack>
#include <utility>
#include <cmath>
#include <tuple>

#include "Entity/Tangible_Entity.hpp"
#include "Behavior/Comportement.hpp"
#include "Behavior/EtatEnum.hpp"

class Comportement;
class Noeud;

class Sentient_Entity : public Tangible_Entity{
	protected:
		
		ETAT etat_entity;
		std::map<Position, Entity> memorisation; /*!<map de mémorisation de l'agent : on stocke pour chaque position qu'il a visionné l'entity présent à cette position à ce moment*/
		Entity* target; /*!<L'endroit que l'entité souhaite atteindre via le chemin'*/
		stack<Position> path; /*!<Le chemin a parcourir pour atteindre la cible'*/
		std::stack<std::tuple<Comportement *,Noeud *, bool>> trace;

	public:
		/*!
		* \brief constructeur avec 2 parametres oú le premier est la
		* position,le deuxieme est le nom de sentient entity concerné
		* et le troisieme son id
		* */
		Sentient_Entity(Position pos, std::map<int, int> charac, std::string, type);
		
		/*!
		 * \brief stockage des alentours de 
		 * l'agent par rapport à sa position correspondante
		 *  dans la map mémorisation*/
		void vision();
		
		/*!
		*\brief Trouve le plus court chemin entre 
		* a postion de l'entité et sa cible. Remplit l'attribut Path
		*\param tar : entité à atteindre
		*\param map : carte du monde
		*/
		void AStar(Entity* tar, vector<vector<int>> map);
		
		int compare2Pos(Position p1, Position p2);
		
		int distEucli(Position ar);

		void run();

		void addToTrace(Comportement * c, Noeud * n);
		void removeTopTrace();
};

#endif
