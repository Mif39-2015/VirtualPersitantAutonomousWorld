//test
#include <iostream>
#include <fstream>
#include <string>
#include "ia/Entity/Characteristics.hpp"

using namespace std;

std::vector<Characteristics> Characteristics::listCharacteristics;

Characteristics * Characteristics::getCharacById(int c){
	for(unsigned int i = 0; i < Characteristics::listCharacteristics.size(); i++){
		if(Characteristics::listCharacteristics[i].getId() == c){
			return &Characteristics::listCharacteristics[i];
		}
	}
	return nullptr;
}

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

void Characteristics::setType(std::string t) {
	this->type = t;
}

void Characteristics::setPrecision(int p) {
	this->precision = p;
}


//récupere les données des chractéristiques du fichier de description et construit une liste de charactéristiques
int Characteristics::loadCharacteristicsFile(std::string fileName){
	ifstream file (PATH_DATA"/descriptionCharacteristics.json", ios::in);
	if (file.is_open()){
		string str((std::istreambuf_iterator<char>(file)), istreambuf_iterator<char>());

		file.close();

		cJSON *root = cJSON_Parse(str.c_str());

		cJSON *child = cJSON_GetObjectItem(root, "characteristics");
		int	nb = cJSON_GetArraySize(child);
		for(int i = 0; i < nb; i++){
			Characteristics charac;
			cJSON *item = cJSON_GetArrayItem(child, i);


			cJSON *id = cJSON_GetObjectItem(item,"id");
			if(id->type == cJSON_Number){
				//~ cout << "id: " << id->valueint << endl;
				charac.setId(id->valueint);
			}

			cJSON *min = cJSON_GetObjectItem(item,"min");
			if(min->type == cJSON_Number){
				charac.setMin(min->valueint);
				//~ cout << "min: " << min->valueint << endl;
			}

			cJSON *max = cJSON_GetObjectItem(item,"max");
			if(max->type == cJSON_Number){
				charac.setMax(max->valueint);
				// cout << "max: " << max->valueint << endl;
			}

			cJSON *name = cJSON_GetObjectItem(item,"name");
			if(name->type == cJSON_String){
				charac.setName(name->valuestring);
				//~ cout << "name: " << name->valuestring << endl;
			}

			cJSON *definition = cJSON_GetObjectItem(item,"definition");
			if(definition->type == cJSON_String){
				charac.setDefinition(definition->valuestring);
				//~ cout << "definition: " << definition->valuestring << endl;
			}

			cJSON *type = cJSON_GetObjectItem(item,"type");
			if(type->type == cJSON_String){
				charac.setType(type->valuestring);
				//~ cout << "type: " << type->valuestring << endl;
			}

			cJSON *precision = cJSON_GetObjectItem(item,"precision");
			if(precision->type == cJSON_Number){
				charac.setPrecision(precision->valueint);
				// cout << "precision: " << precision->valueint << endl;
			}


            listCharacteristics.push_back(charac);
		}

	} else {
		std::cout << "Unable to open general Characteristics file" << std::endl;
		return -1;
	}

	return 0;
}
