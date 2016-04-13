//test
#include <iostream>
#include <fstream>
#include <string>
#include "Entity/Characteristics.hpp"
#include "Tools/Tools.hpp"

using namespace std;

std::vector<Characteristics> CharacteristicsList::listCharacteristics;

//getter
int Characteristics::getId() {
	return this->id;
}

int Characteristics::getMin() {
	return this->min;
}

int Characteristics::getMax() {
	return this->max;
}

std::string Characteristics::getName() {
	return this->name;
}

std::string Characteristics::getDefinition() {
	return this->definition;
}

std::string Characteristics::getType() {
	return this->type;
}

int Characteristics::getPrecision() {
	return this->precision;
}


void Characteristics::setId(int i) {
	this->id = i;
}

void Characteristics::setMin(int m) {
	this->min = m;
}

void Characteristics::setMax(int m) {
	this->max = m;
}

void Characteristics::setName(std::string n) {
	this->name = n;
}

void Characteristics::setDefinition(std::string d) {
	this->definition = d;
}

void Characteristics::setType(std::string t) {
	this->type = t;
}

void Characteristics::setPrecision(int p) {
	this->precision = p;
}


//récupere les données des chractéristiques du fichier de description et construit une liste de charactéristiques
int CharacteristicsList::loadCharacteristicsFile(std::string fileName){
	std::string line;
	std::ifstream myfile (fileName, std::ios::in);
	if (myfile.is_open())
	{
        while(std::getline(myfile,line))
        {
            std::cout << line << '\n';
            vector<std::string> resline = cutString(line, ";");
            Characteristics charac;
            charac.setDefinition(resline[4]);
            charac.setName(resline[3]);
            charac.setId(std::stoi(resline[0]));
            charac.setMin(std::stoi(resline[1]));
            charac.setMax(std::stoi(resline[2]));
            charac.setType(resline[5]);
            charac.setPrecision(std::stoi(resline[6]));

            std::cout << charac << std::endl;

            CharacteristicsList::listCharacteristics.push_back(charac);
        }
        myfile.close();
	}

	else{
		std::cout << "Unable to open file" << std::endl;
		return -1;
	}
	return 0;
}
