#include <fstream>

#include "ia/Tools/Tools.hpp"

std::string readFileForName(std::string filename){
    ifstream file (filename, ios::in);
    if (file.is_open()){
        string str((std::istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
		
        std::vector<std::string> vect;
        file.close();

        cJSON *root = cJSON_Parse(str.c_str());
		
        cJSON *child = cJSON_GetObjectItem(root, "nameList");
        int	nb = cJSON_GetArraySize(child);
        for(int i = 0; i < nb; i++){
            cJSON *item = cJSON_GetArrayItem(child, i);
			
            cJSON *name = cJSON_GetObjectItem(item,"name");
            if(name->type == cJSON_String){
                vect.push_back(name->valuestring);
            }
        }
        int i = rand<int>(0, vect.size());

        return vect[i];
    }
	
    //~ std::ifstream fichier(filename, std::ios::in);  // on ouvre le fichier en lecture
//~ 
    //~ if(fichier){  // si l'ouverture a réussi
    //~ std::vector<std::string> vect;
    //~ std::string line;
    //~ while(std::getline(fichier, line)){
    //~ if (line != "")
    //~ vect.push_back(line);
    //~ }
    //~ fichier.close();  // on ferme le fichier
//~ 
    //~ int i = rand<int>(0, vect.size());
//~ 
    //~ return vect[i];
    //~ }

    else {
        return "noname";
    }
}

std::string getRandomMaleName(){
    return readFileForName(PATH_DATA"/nameListMale.json");
}

std::string getRandomFemaleName(){
    return readFileForName(PATH_DATA"/nameListFemale.json");
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

map<pair<int,int>, char>getMap(string nomFichier){
	ifstream fichier(nomFichier, ios::in);  // on ouvre	
	string ligne;
	map<pair<int,int>, char> carte;
	int l = 0;
	if(fichier)
	{			      
		while(getline(fichier, ligne))  // tant que l'on peut mettre la ligne dans "contenu"
		{
			for(unsigned int i = 0; i < ligne.size(); i++)
			{   
				char caractere = ligne.at(i);// notre variable où sera stocké le caractère
				carte[make_pair(i,l)] = caractere;		
			}
			l++;
		}
		fichier.close();
		return carte;
	}
	else
		cerr << "Impossible d'ouvrir le fichier !" << endl;
}
