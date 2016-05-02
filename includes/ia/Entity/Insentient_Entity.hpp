#ifndef INSENTIENT_ENTITY_HPP
#define INSENTIENT_ENTITY_HPP
/*!
 * \file Insentient_Entity.hpp
 * \brief contient la classe Insentient_Entity
 * \author Groupe IA
 */
#include "ia/Entity/Tangible_Entity.hpp"
#include "ia/Tools/Vector3.hpp"
#include "ia/Entity/Characteristics.hpp"

/*! \class Insentient_Entity
   * \brief Classe contenant les attributs et methodes nécessaires pour la gestion des entités tangibles
   */
class Insentient_Entity : public Tangible_Entity {

public:

	/*!
	* \brief Le constructeur d'instanciation d'un entité tangible
	* \param n: le nom de l'entité
	* \param tid: le type de l'entité
	* \param charac: la map de correspondance entre l'entité et les caractéristiques
	* \param o: la orientation de l'entité
	* \param x : la coordonée x de l'entite
	* \param y : la coordonée y de l'entite
	* */
	Insentient_Entity(std::string n, type tid, std::map<int, int> charac, int x, int y);

	/*!
	* \brief Renvoie la valeur de la clé id de la map.
	* \param id: la clé dans le map
	* \return La valeur de la clé existante, -1 sinon
	* */
	int getValById(int id);

	/*!
	* \brief Met à jour la valeur de la clé associée
	* \param id: la clé dans le map
	* \param v: la valeur associée à la clé
	* \return 1 si la mise à jour a réussi, -1 sinon
	* */
	int setValById(int id, int v);

	/*!
	* \brief Fonction qui update la ressource, qui regenere ses item etc.
	* \param wstime: Le temps actuel de la simulation
	*/
	void updateResource(unsigned int wstime);

	 cJSON* toJson();

	void affiche();

protected:
	std::map<int, int> characteristics;/*!< la map de correspondance entre l'entité et les caractéristiques*/
};

#endif
