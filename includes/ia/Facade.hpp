#ifndef FACADE_HPP
#define FACADE_HPP

#include <cstdlib>
#include <vector>

#include "Entity/Entity.hpp"
#include "Entity/Sentient_Entity.hpp"
#include "Entity/Insentient_Entity.hpp"
#include "Entity/Tribe.hpp"
#include "Tools/Factories.hpp"

/*!
* \class Facade
* \brief Classe qui permet d'accéder à toutes les données concernant l'IA de la simulation.
*/
class Facade {
public:

	/*!
	* \brief Initialise la simulation pour l'IA
	* \param nbAg: Le nombre d'agents au début de la simulation
	* \param nbAn: Le nombre d'animaux au début de la simulation
	*/
	void initSimulation(int nbAg, int nbAn);

	/*!
	* \brief Permet d'appeler la fonction run pour tout les agents.
	*/
	void runAll();

	/*!
	* \brief Permet de faire un tick d'horloge pour tout les insentient_entity de la simulation
	*/
	void updateWorld();

	/*!
	* \brief Retourne un agent selon un id
	* \param i: l'id recherché
	*/
	Sentient_Entity * getAgentById(unsigned int i);

	/*!
	* \brief Retourne un clan selon un id
	* \param i: l'id recherché
	*/
	Tribe * getTribeById(unsigned int i);
	
	/*!
	* \brief Retourne la liste des objets qui ont été modifiés lors de la dernière itération 
	*/
	std::vector<Entity *> getChanges();

	std::vector<Sentient_Entity *> listAgent;
	std::vector<Tribe *> listTribe;
	std::vector<Insentient_Entity *> listIE;

private:
};

#endif /*FACADE_HPP*/
