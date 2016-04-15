#include "Tools/Tools.hpp"
#include <fstream>

std::string readFileForName(std::string filename) {
	std::ifstream fichier(filename, std::ios::in);  // on ouvre le fichier en lecture

	if (fichier) { // si l'ouverture a réussi
		std::vector<std::string> vect;
		std::string line;
		while (std::getline(fichier, line)) {
			if (line != "")
				vect.push_back(line);
		}
		fichier.close();  // on ferme le fichier

		int i = rand<int>(0, vect.size());

		return vect[i];
	}

	else  return "noname";
}

std::string getRandomMaleName() {
	// return readFileForName("data/nameListMale.txt");
	return readFileForName("../../../data/nameListMale.txt");
}

std::string getRandomFemaleName() {
	// return readFileForName("data/nameListFemale.txt");
	return readFileForName("../../../data/nameListFemale.txt");
}

std::vector<std::string> cutString(std::string & str, std::string delimiter) {
	size_t pos = 0;
	std::vector<std::string> res;
	std::string token;
	while ((pos = str.find(delimiter)) != std::string::npos) {
		token = str.substr(0, pos);
		res.push_back(token);
		str.erase(0, pos + delimiter.length());
	}
	res.push_back(str);

	return res;
}
