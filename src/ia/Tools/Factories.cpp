#include "Tools/Factories.hpp"

Sentient_Entity * Factories::createAgent(){
    std::vector<int> characs;
    std::string line;
    // std::ifstream myfile ("data/Characteristics_Agent.txt", std::ios::in);
    std::ifstream myfile ("../../../data/Characteristics_Agent.txt", std::ios::in);
    if (myfile.is_open())
    {
        while(std::getline(myfile,line))
        {
            characs.push_back(std::stoi(line));

        }
        myfile.close();
    }

    else{
        std::cout << "Unable to open file for the Agent Characteristics" << std::endl;
        return nullptr;
    }

    std::map<int, int> characs_val;
    for (std::vector<int>::iterator it = characs.begin(); it != characs.end(); it++)
    {
        int min = CharacteristicsList::listCharacteristics[*it].getMin();
        int max = CharacteristicsList::listCharacteristics[*it].getMax();
        int val = rand (min, max+1);
        characs_val.insert(std::pair<int,int>(*it,val));
    }

    std::string name;
    if (characs_val[1] == 0)
        name = getRandomMaleName();
    else
        name = getRandomFemaleName();

    return new Sentient_Entity(Position(0,0), characs_val, name,  ID_AGENT);
}

Sentient_Entity * Factories::createAnimal(){
    std::vector<int> characs;
    std::string line;
    // std::ifstream myfile ("data/Characteristics_Animal.txt", std::ios::in);
    std::ifstream myfile ("../../../data/Characteristics_Animal.txt", std::ios::in);
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
        std::cout << "Unable to open file for the Animal Characteristics" << std::endl;
        return nullptr;
    }

    std::map<int, int> characs_val;
    for (std::vector<int>::iterator it = characs.begin(); it != characs.end(); it++)
    {
        int min = CharacteristicsList::listCharacteristics[*it].getMin();
        int max = CharacteristicsList::listCharacteristics[*it].getMax();
        int val = rand (min, max+1);
        characs_val.insert(std::pair<int,int>(*it,val));
    }

    return new Sentient_Entity(Position(0,0), characs_val, "mouton", ID_ANIMAL);
}

Item * Factories::createItem(){
    std::vector<int> characs;
    std::string line;
    // std::ifstream myfile ("data/Characteristics_Animal.txt", std::ios::in);
    std::ifstream myfile ("../../../data/Characteristics_Item.txt", std::ios::in);
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
        std::cout << "Unable to open file for the Item Characteristics" << std::endl;
        return nullptr;
    }

    std::map<int, int> characs_val;
    for (std::vector<int>::iterator it = characs.begin(); it != characs.end(); it++)
    {
        int min = CharacteristicsList::listCharacteristics[*it].getMin();
        int max = CharacteristicsList::listCharacteristics[*it].getMax();
        int val = rand (min, max+1);
        characs_val.insert(std::pair<int,int>(*it,val));
    }

    return new Item("placeholder_item_name", ID_ITEM, characs_val);
}


Tribe * Factories::createTribe(){
    std::vector<int> characs;
    std::string line;
    // std::ifstream myfile ("data/Characteristics_Animal.txt", std::ios::in);
    std::ifstream myfile ("../../../data/Characteristics_Tribe.txt", std::ios::in);
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
        std::cout << "Unable to open file for the Tribe Characteristics" << std::endl;
        return nullptr;
    }

    std::map<int, int> characs_val;
    for (std::vector<int>::iterator it = characs.begin(); it != characs.end(); it++)
    {
        int min = CharacteristicsList::listCharacteristics[*it].getMin();
        int max = CharacteristicsList::listCharacteristics[*it].getMax();
        int val = rand (min, max+1);
        characs_val.insert(std::pair<int,int>(*it,val));
    }

    return new Tribe("placeholder_tribe_name", 0, ID_TRIBE, characs_val);
}
