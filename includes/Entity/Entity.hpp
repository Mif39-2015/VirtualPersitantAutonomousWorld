#ifndef ENTITY_HPP
#define ENTITY_HPP
/*!
 * \file Entity.hpp
 * \brief contient la classe Entity
 * \author Groupe IA
 */
#include <string>
#include <map>
#include "../../src/tool/cJSON.hpp"

using namespace std;
/*!
* C'est l'enumeration des types possibles
* pour les entités
* */
enum type{
	ID_AGENT,/*!< signifie que l'entity est un agent*/
	ID_ANIMAL,/*!< signifie que l'entity est un animal*/
	ID_BUILDING,/*!< signifie que l'entity est un building*/
	ID_RESSOURCE,/*!< signifie que l'entity est une ressource*/
	ID_ITEM,/*!< signifie que l'entity est un item*/
	ID_TRIBE /*!< signifie que l'entity est un tribu*/
};

static const char* TypeNames[] = {
	"ID_AGENT",
	"ID_ANIMAL",
	"ID_BUILDING",
	"ID_RESSOURCE",
	"ID_ITEM",
	"ID_TRIBE"
};
/*! \class Entity
   * \brief Classe contenant les attributs et methodes nécessaires pour la gestion des entités
   */
class Entity{

	public:
		/*!
		* \brief Le constructeur pour l'instanciation d'une entité
		* */
        Entity(std::string,type,std::map<int, int> charac);
		/*!
		* \brief Renvoie l'id de l'entity
		* */
		unsigned int getId();
		/*!
		* \brief Renvoie le nom de l'entity
		* */
		string getName();
		/*!
		* \brief Renvoie le modificateur de l'entity
		* */
		bool getModif();
		/*!
		* \brief Renvoie le type associé à l'entity
		* */
		type getTypeId();
		/*!
		* \brief Met à jour le modificatuer de l'entity
		* \param m: le modificateur
		* */
		void setModif(bool m);
		/*!
		* \brief Met à jour le nom de l'entity
		* \param n: le nom
		* */
		void setName(std::string n);

		/*!
		* \brief Renvoie la valeur de la clé id de la map.
		* \param id: la clé dans le map
		* \return La valeur de la clé existante, -1 sinon
		* */
		int getVal(int id);

		/*!
		* \brief Met à jour la valeur associée à la clé id si cette derniere
		* existe bien dans la map et renvoie 1 (success) sinon renvoie -1
		* \param id: la clé
		* \param v: la valeur
		* */
		int setVal(int id, int v);

		cJSON* toJson();

		~Entity(void);

	protected:

		static unsigned int idCount;
		unsigned int id; /*!< l'id unique d'un entity*/
		type typeId; /*!< le type associé à l'entity*/
		string name; /*!< le nom de l'objet entity*/
		std::map<int, int> charact_correspondence; /*!<correspondance entre la caracteristique et le sentient entity.*/
		bool modif;
};

#endif
