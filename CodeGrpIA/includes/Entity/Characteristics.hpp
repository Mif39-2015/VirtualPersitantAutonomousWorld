#ifndef CHARACTERISTICS_HPP
#define CHARACTERISTICS_HPP

/*!
 * \file Characteristics.hpp
 * \brief Fichier contenant les classes Characteristics et CharacteristicsList
 * \author Groupe IA
 */

#include <vector>
#include <iostream>
/*! 
* \class Characteristics
* \brief classe permettant de représenter les caractéristiques
*/
class Characteristics{

	public:
		//getters
		int getId();
		int getMin();
		int getMax();
		std::string getName();
		std::string getDefinition();
		std::string getType();
		int getPrecision();

		//setters
		void setId(int i);
		void setMin(int m);
		void setMax(int m);
		void setName(std::string n);
		void setDefinition(std::string d);
		void setType(std::string t);
		void setPrecision(int p);

		friend std::ostream & operator<<(std::ostream & os, Characteristics const & obj){
		    // write obj to stream
			os << obj.id << std::endl;
			os << obj.name << std::endl;
			os << obj.type << std::endl;
			os << obj.definition << std::endl;
			os << "Between " << obj.min << " and " << obj.max << std::endl;
		    return os;
		}

	private:
		int id; /*!<Identifiant unique de la caractéristique*/
		int min; /*!<Valeur minimale de la caractéristique*/
		int max; /*!<Valeur maximale de la caractéristique*/
		std::string name; /*!<Nom de la caractéristique*/
		std::string definition; /*!<Définition de la caractéritisque*/
		std::string type; /*!<Type de la caractéristique (pourcentage, valeur fixe)*/
		int precision; /*!<Précision avec laquelle la valeur doit être interpretée*/

	};

/*! 
* \class CharacteristicsList
* \brief classe permettant de gérer les caractéristiques sous forme d'une liste
*/
class CharacteristicsList{

public:

	static std::vector<Characteristics> listCharacteristics; /*!<Liste de toutes les caractéristiques existantes*/

	/*!
	 *  \brief Créé la liste de caractéristiques à partir d'un fichier texte
	 *  \param fileName : le nom du fichier contenant la description des caractéristiques
	 */
	static int loadCharacteristicsFile(std::string fileName);

};

#endif
