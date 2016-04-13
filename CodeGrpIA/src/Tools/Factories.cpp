#include "Tools/Factories.hpp"

Sentient_Entity * Factories::createAgent(){

	std::vector<int> characs;
	std::string line;
	std::ifstream myfile ("data/Characteristics_Agent.txt", std::ios::in);
	if (myfile.is_open())
	{
		while(std::getline(myfile,line))
		{
		    characs.push_back(std::stoi(line));

		}
		myfile.close();
	}

	else{
		std::cout << "Unable to open file" << std::endl;
		return nullptr;
	}

	std::map<int, int> characs_val;
	for (std::vector<int>::iterator it = characs.begin(); it != characs.end(); it++)
	{
		int min = CharacteristicsList::listCharacteristics[*it].getMin();
		int max = CharacteristicsList::listCharacteristics[*it].getMax();
		int val = rand (min, max);
		characs_val.insert(std::pair<int,int>(*it,val));
	}

	std::string name;
	if (characs_val[1] == 0)
		name = getRandomMaleName();
	else
		name = getRandomFemaleName();

	return new Sentient_Entity(Position(0,0), name, ID_AGENT);
}

Sentient_Entity * Factories::createAnimal(){

	std::vector<int> characs;
	std::string line;
	std::ifstream myfile ("data/Characteristics_Animal.txt", std::ios::in);
	if (myfile.is_open())
	{
		while(std::getline(myfile,line))
		{
			if (line != "")
				characs.push_back(std::stoi(line));

		}
		myfile.close();
	}

	else{
		std::cout << "Unable to open file" << std::endl;
		return nullptr;
	}

	std::map<int, int> characs_val;
	for (std::vector<int>::iterator it = characs.begin(); it != characs.end(); it++)
	{
		int min = CharacteristicsList::listCharacteristics[*it].getMin();
		int max = CharacteristicsList::listCharacteristics[*it].getMax();
		int val = rand (min, max);
		characs_val.insert(std::pair<int,int>(*it,val));
	}

	return new Sentient_Entity(Position(0,0), "mouton", ID_ANIMAL);
}
