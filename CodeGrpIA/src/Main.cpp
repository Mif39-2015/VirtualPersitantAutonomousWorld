#include <iostream>

#include "Tools.hpp"

int main(int argc, char const *argv[])
{
	/* code */
	for(int i = 0; i < 15; i++){
		std::cout << getRandomMaleName() << std::endl;
		std::cout << getRandomFemaleName() << std::endl << std::endl;
	}

	return 0;
}