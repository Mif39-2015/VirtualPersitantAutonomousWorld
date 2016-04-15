#ifndef FACADE_HPP
#define FACADE_HPP

#include <cstdlib>
#include <vector>

#include "Entity/Entity.hpp"
#include "Entity/Sentient_Entity.hpp"
#include "Entity/Insentient_Entity.hpp"
#include "Entity/Tribe.hpp"

/*!
* \class Facade
* \brief Classe qui permet d'accéder à toutes les données concernant l'IA de la simulation.
*/
class Facade {
public:

	/*!
	* \brief Initialise la simulation pour l'IA
	* \param nbAg: Le nombre d'agents au début de la simulation
	*/
	static void initSimulation(int nbAg);

	/*!
	* \brief Permet d'appeler la fonction run pour tout les agents.
	*/
	static void runAll();

	/*!
	* \brief Permet de faire un tick d'horloge pour tout les insentient_entity de la simulation
	*/
	static void updateWorld();

	/*!
	* \brief Retourne un agent selon un id
	* \param i: l'id recherché
	*/
	static Sentient_Entity * getAgentById(unsigned int i);

	/*!
	* \brief Retourne un clan selon un id
	* \param i: l'id recherché
	*/
	static Tribe * getTribeById(unsigned int i);

private:
	static std::vector<Sentient_Entity *> listAgent;
	static std::vector<Tribe *> listTribe;
	static std::vector<Insentient_Entity *> listIE;
};

#endif /*FACADE_HPP*/
