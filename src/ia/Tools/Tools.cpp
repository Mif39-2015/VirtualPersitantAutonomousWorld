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
