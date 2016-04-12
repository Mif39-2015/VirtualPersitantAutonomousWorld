#ifndef FACTORIES_HPP
#define FACTORIES_HPP

#include "Agent.hpp"
#include "Tools.hpp"

class AgentFactory{

public:
	static Sentient_Entity * createAgent(){
		//Charger le fichier qui correspondeau carac de l'agent.
		//Ce fichier va contenir une liste d'ID de carac.
		//Avec cette liste d'id de carac,
		//on va piocher remplir la map des Sentient_Entity avec les id et des valeurs choisi (random ou pas)
	}
};

#endif
