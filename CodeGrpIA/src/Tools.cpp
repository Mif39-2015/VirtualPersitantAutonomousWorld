#include "Tools.hpp"
#include <fstream>
#include <vector>


std::string getRandomMaleName(){
	std::ifstream fichier("data/nameListMale.txt", std::ios::in);  // on ouvre le fichier en lecture

	if(fichier){  // si l'ouverture a réussi
		std::vector<std::string> vect;
		std::string line;
		while(std::getline(fichier, line)){
			vect.push_back(line);
		}
		fichier.close();  // on ferme le fichier

		int i = rand<int>(0, vect.size());

		return vect[i];
	}

	else  return "noname";
}

std::string getRandomFemaleName(){
	std::ifstream fichier("data/nameListFemale.txt", std::ios::in);  // on ouvre le fichier en lecture

	if(fichier){  // si l'ouverture a réussi
		std::vector<std::string> vect;
		std::string line;
		while(std::getline(fichier, line)){
			vect.push_back(line);
		}
		fichier.close();  // on ferme le fichier

		int i = rand<int>(0, vect.size());

		return vect[i];
	}

	else  return "noname";
}