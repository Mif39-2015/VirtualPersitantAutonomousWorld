#ifndef TRIBE_HPP
#define TRIBE_HPP

#include "Agent.hpp"
// #include "Goal.hpp" //Uncomment when Goal is implemented
#include "Item.hpp"
// #include "Complex_Behavior.hpp" //Uncomment when Complex_Behavior is implemented

#include <string>
#include <map>
#include <vector>

class Tribe {
public:
	//Uncomment when Agent, Goal and Complex_Behavior are implemented
	std::vector<Agent> population;
	// std::vector<Goal> goal_list;
	// std::map<Complex_Behavior, int> job_repartition;

	std::map<Item, int> stock;

	Tribe(unsigned int, std::string, unsigned int);

	~Tribe();

private:
	unsigned int id;
	std::string name;
	unsigned int goal_index;	
};

#endif
