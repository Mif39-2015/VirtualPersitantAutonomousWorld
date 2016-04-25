#ifndef TRIBE_HPP
#define TRIBE_HPP

/*!
* \file Tribe.hpp
* \brief contient la classe Tribe
* \author Groupe IA
*/

//#include "Complex_Behavior.hpp" //Uncomment if Complex_Behavior will be implemented
//#include "Goal.hpp" //Uncomment if Goal will be implemented
#include "ia/Entity/Entity.hpp"
#include "ia/Entity/Item.hpp"
#include <string>
#include <map>
#include <vector>


/*! \class Tribe
* \brief Classe contenant les methodes et les attributs pour gérér les tribus des entités
*/

class Tribe : public Entity{

	public:
	
		/*!
	     	*  \brief Constructeur pour la classe Tribe
	     	*/
		Tribe();

		/*!
	     	*  \brief Constructeur pour la classe Tribe
	     	*/
		Tribe(std::string, unsigned int, type, std::map<int, int> charac);

		/*!
	     	*  \brief Fonction d'accesseur qui renvoie la valeur de goal_index
	     	*  \return goal_index
	     	*/
		unsigned int getGoalIndex();

		/*!
	     	*  \brief Fonction d'accesseur qui renvoie la valeur de la population dans un tribu
	     	*  \return integer
	     	*/
		int getPopulationSize();

		/*!
	     	*  \brief Fonction d'accesseur qui renvoie le nombre total des batiments dans un tribu
	     	*  \return integer
	     	*/
		int getNbBuildings();

		/*!
	     	*  \brief Fonction d'accesseur qui renvoie le nombre total des ressources dans un tribu
	     	*  \return integer
	     	*/
		int getNbRessources();

		/*!
	     	*  \brief Fonction d'accesseur qui renvoie la valeur de la quantité pour un article
	     	*  \param i: l'id d'un article
	     	*  \return integer
	     	*/
		int getQuantityByItem(Item* i);

		/*!
	     	*  \brief Fonction d'accesseur qui renvoie la taille d'un tribu (le nombre tous les types d'entités)
	     	*  \return integer
	     	*/
		int getTribeSize();

		/*!
	     	*  \brief Fonction de mutateur qui met à jour la valeur de goal_index
	     	*  \param _goal_index: l'objectif d'un tribu
	     	*/
		void setGoalIndex(unsigned int _goal_index);

		/*!
	     	*  \brief Ajoute une entité dans la liste de membres
	     	*  \param a: l'entité qui sera ajouté
	     	*/
		void addNewEntity(Entity* a);

		/*!
	     	*  \brief Ajoute un article avec sa quantité dans le stock
	     	*  \param i: l'id de l'article
	     	*  \param quantity: la quantité de l'article
	     	*/
		void addItemToStock(Item* i, int quantity);

			/*!
	     	*  \brief Affiche la liste de stock
	     	*/
		void afficheStock();
		
		void afficheMembres();
		
		void affiche();

		/*!
	     	*  \brief Affichage sous le format json
	     	*/
		cJSON* toJson();

		/*!
	     	*  \brief Destructeur pour la classe Tribe
	     	*/
		~Tribe(void);


	private:

		unsigned int id; /*!< L'id d'un tribu*/
		std::string name; /*!< Le nom d'un tribu*/
		unsigned int goal_index; /*!< L'index de l'objectif d'un tribu */
		std::vector<Entity*> members; /*!< Liste de tous les entités qu'un tribu possède */
		std::map<Item*, int> stock; /*!< Conteneur qui associe la valeur de la quantité à chaque article du stock dans un tribu */
		//std::vector<Goal> goal_list;
		//std::map<Complex_Behavior, int> job_repartition;

};

#endif
