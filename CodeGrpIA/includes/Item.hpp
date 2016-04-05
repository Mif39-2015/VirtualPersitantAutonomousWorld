#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>

class Item{

public:
	Item(unsigned int, std::string, float);

	~Item(void);

private:
	unsigned int id;
	std::string name;
	float weight;

};

#endif
