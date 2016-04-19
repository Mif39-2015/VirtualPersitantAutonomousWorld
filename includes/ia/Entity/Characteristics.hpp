#ifndef CHARACTERISTICS_HPP
#define CHARACTERISTICS_HPP

#include <vector>

#include "ia/Tools/Tools.hpp"
#include "tool/cJSON.hpp"

class Characteristics {

public:

	/*!
	* \brief Les caractéristiques provenant du fichier
	* */
	static std::vector<Characteristics> listCharacteristics;

	/*!
	* \brief Construit un vecteur de caractéristiques à partir du fichier donné
	* \param fileName: le fichier donné
	* */
	static int loadCharacteristicsFile(std::string fileName);

	static Characteristics * getCharacById(int c);

	/*!
	* \brief Renvoie l'id de la caractéristique
	* */
	int getId();
	/*!
	* \brief Renvoie la valeur minimale de l'intervalle [min, max]
	* */
	int getMin();
	/*!
	* \brief Renvoie la valeur maximale de l'intervalle [min, max]
	* */
	int getMax();
	/*!
	* \brief Renvoie le nom de la caractéristique
	* */
	std::string getName();
	/*!
	* \brief Renvoie la definition
	* */
	std::string getDefinition();
	/*!
	* \brief Renvoie le type de la caractéristique
	* */
	std::string getType();
	/*!
	* \brief Renvoie la précision
	* */
	int getPrecision();

	/*!
	* \brief Met à jour l'id de la caractéristique
	* \param i: l'id de la caractéristique
	* */
	void setId(int i);
	/*!
	* \brief Met à jour la valeur minimale de la caractéristique
	* \param m: la valeur minimale
	* */
	void setMin(int m);
	/*!
	* \brief Met à jour la valeur maximale de la caractéristique
	* \param m: la valeur maximale
	* */
	void setMax(int m);
	/*!
	* \brief Met à jour le nom de la caractéristique
	* \param n: le nom de la caractéristique
	* */
	void setName(std::string n);
	/*!
	* \brief Met à jour  la definition de la caractéristique
	* \param d: la définition
	* */
	void setDefinition(std::string d);
	/*!
	* \brief Met à jour le type de la caractéristique
	* \param t: le type
	* */
	void setType(std::string t);
	/*!
	* \brief Met à jour la précision
	* \param p: la précision
	* */
	void setPrecision(int p);



private:
	int id;/*! <l'id de la caractéristique*/
	int min;/*! <la valeur minimale de l'intervalle [min, max] parmi les valeurs possibles*/
	int max;/*!< la valeur maximale de l'intervalle [min, max] parmi les valeurs possibles*/
	std::string name;/*!< le nom de la caracterstique*/
	std::string definition;/*!< la definition de la caractéristique*/
	std::string type;/*! le type de la caractéristique<*/
	int precision;/*!< la précision */
};

enum Characs {
	C_VITALITY           = 0,
	C_GENDER             = 1,
	C_AGE  	             = 2,
	C_AGRESSIVENESS      = 3,
	C_FITNESS            = 4,
	C_SATIETY            = 5,
	C_SATIETY_THRESHOLD  = 6,
	C_REFLEX             = 7,
	C_PERCEPTION         = 8,
	C_INDEPENDENCE       = 9,
	C_CHARISMA           = 10,
	C_CAPACITY           = 11,
	C_STAMINA            = 12,
	C_STAMINA_THRESHOLD  = 13,
	C_SANITY             = 14,
	C_RESPAWN_RATE       = 15,
	C_RESPAWN_VALUE      = 16,
	C_ORIENTATION        = 17,
	C_STRUCTURAL_POINT   = 18,
	C_WEIGHT             = 19,
	C_MAXRESSTOCK        = 20
};

#endif
