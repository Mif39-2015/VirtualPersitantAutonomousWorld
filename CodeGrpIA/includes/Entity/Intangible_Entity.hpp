#ifndef INANGIBLE_ENTITY_HPP
#define INANGIBLE_ENTITY_HPP

/*!
 * \file Intangible_Entity.hpp
 * \brief Fichier contenant la classe Intangible_Entity
 * \author Groupe IA
 */

#include "Entity/Entity.hpp"

using namespace std;
/*! 
* \class Intangible_Entity
* \brief classe permettant de représenter les entités intangibles (Item, Tribe)
*/
class Intangible_Entity : public Entity {

public:
    Intangible_Entity(std::string, std::string);
};


#endif /* INANGIBLE_ENTITY_HPP */

