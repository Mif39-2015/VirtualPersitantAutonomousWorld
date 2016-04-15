//test
#include <iostream>
#include <fstream>
#include <string>
#include "Entity/Characteristics.hpp"

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
int CharacteristicsList::loadCharacteristicsFile(std::string fileName){
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
				cout << "max: " << max->valueint << endl;
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
				cout << "precision: " << precision->valueint << endl;
			}
			
            
            CharacteristicsList::listCharacteristics.push_back(charac);
		}
		
	} else {
		std::cout << "Unable to open general Characteristics file" << std::endl;
		return -1;
	}
	
	
	//~ 
	//~ std::string line;
	//~ std::ifstream myfile (fileName, std::ios::in);
	//~ if (myfile.is_open())
	//~ {
        //~ while(std::getline(myfile,line))
        //~ {
            //~ std::cout << line << '\n';
            //~ vector<std::string> resline = cutString(line, ";");
            //~ Characteristics charac;
            //~ charac.setDefinition(resline[4]);
            //~ charac.setName(resline[3]);
            //~ charac.setId(std::stoi(resline[0]));
            //~ charac.setMin(std::stoi(resline[1]));
            //~ charac.setMax(std::stoi(resline[2]));
            //~ charac.setType(resline[5]);
            //~ charac.setPrecision(std::stoi(resline[6]));
//~ 
            //~ CharacteristicsList::listCharacteristics.push_back(charac);
        //~ }
        //~ myfile.close();
	//~ }
//~ 
	//~ else{
		//~ std::cout << "Unable to open general Characteristics file" << std::endl;
		//~ return -1;
	//~ }
	return 0;
}
