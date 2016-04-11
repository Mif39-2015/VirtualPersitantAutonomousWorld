//test
#include <iostream>
#include <fstream>

#include "Characteristics.hpp"

using namespace std;


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

int Characteristics::getPrecision() {
	return this->precision;
}


//setter
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

void Characteristics::setPrecision(int p) {
	this->precision = p;
}


//récupere les données des chractéristiques du fichier de description et construit une liste de charactéristiques
int CharacteristicsList::loadCharacteristicsFile(std::string fileName){
	std::string line;
	std::ifstream myfile (fileName, std::ios::in);
	if (myfile.is_open())
	{
            while ( std::getline (myfile,line) )
            {
                std::cout << line << '\n';
            }
            myfile.close();
	}

	else std::cout << "Unable to open file"; 
	return 1;
}