#include <iostream>

#include "Resource.hpp"
#include "Agent.hpp"
#include "Building.hpp"
#include "Animal.hpp"
#include "Characteristics.hpp"
#include "Factories.hpp"

int main(int argc, char const *argv[])
{
	/* code */
	// for(int i = 0; i < 15; i++){
	// 	std::cout << getRandomMaleName() << std::endl;
	// 	std::cout << getRandomFemaleName() << std::endl << std::endl;
	// }
        
        // Chargement de la liste des carac
	CharacteristicsList::loadCharacteristicsFile("data/descriptionCharacteristics.txt");

	
	Sentient_Entity* ag1 = Factories::createAgent();
	
	Sentient_Entity* an1 = Factories::createAnimal();
	
	return 0;
}
