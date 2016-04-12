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
        
	int a = CharacteristicsList::loadCharacteristicsFile("data/descriptionCharacteristics.txt");

	//Factories::createAgent();
	
	return 0;
}
