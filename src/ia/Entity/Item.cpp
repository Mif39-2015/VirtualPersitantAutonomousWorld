#include <iostream>
#include "Entity/Item.hpp"

std::vector<Item> Item::listItems;
Item::Item(std::string n, type t,std::map<int, int> charac) : Entity(n, t,charac){}

Item::~Item(){}

int Item::loadItemsFile(std::string fileName){
	std::string line;
	std::ifstream myfile (fileName, std::ios::in);
	if (myfile.is_open())
	{
        while(std::getline(myfile,line))
        {
            std::cout << line << '\n';
            vector<std::string> resline = cutString(line, ";");
            std::map<int, int> charact;
            charact.insert(std::pair<int, int>(19, std::stoi(resline[1])));
            string name = resline[0];
            Item item(name, type::ID_ITEM, charact);


            Item::listItems.push_back(item);
        }
        myfile.close();
	}

	else{
		std::cout << "Unable to open general Item file" << std::endl;
		return -1;
	}
}
