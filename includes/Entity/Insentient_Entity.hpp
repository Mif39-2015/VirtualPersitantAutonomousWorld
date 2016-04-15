#ifndef INSENTIENT_ENTITY_HPP
#define INSENTIENT_ENTITY_HPP
/*!
 * \file Insentient_Entity.hpp
 * \brief contient la classe Insentient_Entity
 * \author Groupe IA
 */
#include "Entity/Tangible_Entity.hpp"
#include "Tools/Vector3.hpp"
#include "Characteristics.hpp"

/*! \class Insentient_Entity
   * \brief Classe contenant les attributs et methodes nécessaires pour la gestion des entités tangibles
   */
class Insentient_Entity : public Tangible_Entity{
    public:
        Vector3 sizeIE;/*!< la dimension 3D de l'entité*/
        /*!
		* \brief Le constructeur d'instanciation d'un entité tangible
		* \param n: le nom de l'entité
		* \param tid: le type de l'entité
		* \param charac: la map de correspondance entre l'entité et les caractéristiques
		* \param o: la orientation de l'entité
		* \param x: la postition x de l'entité
		* \param y: la position y de l'entité
		* \param z: la position z de l'entité
		* */
        Insentient_Entity(std::string n, type tid,std::map<int, int> charac, int o, int x, int y, int z);
        /*!
		* \brief Renvoie l'orientation de l'entité
		* */
        int getOrientation();
        /*!
		* \brief Met à jour l'orientation de l'entité
		* */
        void setOrientation(int _o);
        /*!
		* \brief Renvoie le point structural de l'entité tanglible
		* */
        unsigned int getStructuralPoint();
        /*!
		* \brief Met à jour le point structural de l'entité tangible
		* \param sp: le point structural
		* */
        void setStructuralPoint(unsigned int sp);
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
	protected:
        static unsigned int idCount;
        int orientation;/*!< l'orientation de l'entité */
        unsigned int structural_point;/*!< le point structural de l'entité*/
        std::map<int, int> characteristics;/*!< la map de correspondance entre l'entité et les caractéristiques*/
};

#endif
