#ifndef ENTITY_HPP
#define ENTITY_HPP
/*!
 * \file Entity.hpp
 * \brief contient la classe Entity
 * \author Groupe IA
 */
#include <string>
#include <map>
#include "tool/cJSON.hpp"

using namespace std;
/*!
* C'est l'enumeration des types possibles
* pour les entités
* */
enum type {
	ID_AGENT,            /*!< signifie que l'entity est un agent*/
	ID_ANIMAL,           /*!< signifie que l'entity est un animal*/
	ID_BUILDING,         /*!< signifie que l'entity est un building*/
	ID_RESSOURCE_BOIS,   /*!< signifie que l'entity est un arbre*/
	ID_RESSOURCE_PIERRE, /*!< signifie que l'entity est une pierre*/
	ID_RESSOURCE_METAL,  /*!< signifie que l'entity est un gisement de métal*/
	ID_RESSOURCE_VIANDE, /*!< signifie que l'entity est un animal mort (conteneur de viande en général)*/
	ID_RESSOURCE_LEGUME, /*!< signifie que l'entity est un plant de légume*/
	ID_ITEM,             /*!< signifie que l'entity est un item*/
	ID_TRIBE,            /*!< signifie que l'entity est un tribu*/
	ID_VOID              /*!< ID null, signifi que l'entity n'est rien*/
};

static const char* TypeNames[] = {
	"ID_AGENT",
	"ID_ANIMAL",
	"ID_BUILDING",
	"ID_RESSOURCE_BOIS",
	"ID_RESSOURCE_PIERRE",
	"ID_RESSOURCE_METAL",
	"ID_RESSOURCE_VIANDE",
	"ID_RESSOURCE_LEGUME",
	"ID_ITEM",
	"ID_TRIBE",
	"ID_VOID"
};

/*! \class Entity
   * \brief Classe contenant les attributs et methodes nécessaires pour la gestion des entités
   */
class Entity {

public:
	/*!
	* \brief Le constructeur pour l'instanciation d'une entité
	*/
	Entity(std::string, type, std::map<int, int> charac);

	/*!
	* \brief Renvoie l'id de l'entity
	*/
	unsigned int getId();

	/*!
	* \brief Renvoie le nom de l'entity
	* */
	string getName();
	/*!
	* \brief Renvoie le modificateur de l'entity
	*/
	bool getModif();

	/*!
	* \brief Renvoie l'etat Idle de l'entity
	*/
	bool getIdle();

	/*!
	* \brief Renvoie le type associé à l'entity
	*/
	type getTypeId();

	/*!
	* \brief Met à jour le modificatuer de l'entity
	* \param m: le modificateur
	*/
	void setModif(bool m);

	/*!
	* \brief Met à jour l'etat de l'entity : si il est idle ou non
	* \param m: le nouvel etat
	*/
	void setIdle(bool i);

	/*!
	* \brief Modifie le type de l'entity
	*/
	void setTypeId(type tid);

	/*!
	* \brief Met à jour le nom de l'entity
	* \param n: le nom
	*/
	void setName(std::string n);

	/*!
	* \brief Renvoie la valeur de la clé id de la map.
	* \param id: la clé dans le map
	* \return La valeur de la clé existante, -1 sinon
	*/
	int getVal(int id);

	/*!
	* \brief Met à jour la valeur associée à la clé id
	* \param id: la clé
	* \param v: la valeur
	* \return -1 si l'id ne correspond pas à l'une des caractéristiques de l'entity, -2 si v est plus grand que le max, -3 si v est plus petit que le min, 1 si tout vas bien
	*/
	int setVal(int id, int v);

	/*!
	* \brief Fait évoluer l'état d'un agent de manière passive
	* \param wstime: Le temps de la simulation
	*/
	void decade(unsigned int wstime);

	/*!
	* \brief Retourne si une entitée à faim.
	* \return 1 si l'entity a faim, 0 si non, et -1 si erreur
	*/
	unsigned int isHungry(void);

	/*!
	* \brief Retourne si une entitée est fatiguée.
	* \return 1 si l'entity est fatiguée, 0 si non, et -1 si erreur
	*/
	unsigned int isTired(void);
	
	void reinitModif();

	virtual void affiche();

	virtual cJSON* toJson();

	virtual ~Entity(void);

protected:

	static unsigned int idCount;
	unsigned int id; /*!< l'id unique d'un entity*/
	type typeId; /*!< le type associé à l'entity*/
	string name; /*!< le nom de l'objet entity*/
	std::map<int, int> charact_correspondence; /*!<correspondance entre la caracteristique et le sentient entity.*/
	bool modif;
	bool idle;
};

#endif
