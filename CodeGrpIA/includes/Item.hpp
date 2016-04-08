#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>

class Item{

public:
	Item(unsigned int, std::string, float);
	
	const unsigned int& getID();
	
	const std::string& getName();
	
	const float& getWeight();
	
	//pas de set, les valeurs ne seront pas forcément modifiables

	~Item(void);

private:
	unsigned int id;
	std::string name;
	float weight;

};

#endif
