#ifndef TRIBE_HPP
#define TRIBE_HPP

#include "Includes.hpp"

#include "Sentient_Entity.hpp"
// #include "Goal.hpp" //Uncomment when Goal is implemented
#include "Item.hpp"
// #include "Complex_Behavior.hpp" //Uncomment when Complex_Behavior is implemented

#include <string>
#include <map>
#include <vector>

class Tribe {
	public:
		//Uncomment when Agent, Goal and Complex_Behavior are implemented
		std::vector<Sentient_Entity> population;
		// std::vector<Goal> goal_list;
		// std::map<Complex_Behavior, int> job_repartition;

		std::map<Item, int> stock;

		Tribe(unsigned int, std::string, unsigned int);
		unsigned int getId();
		std::string getName();
		unsigned int getGoalIndex();
		void setId(unsigned int _id);
		void setName(std::string _n);
		void setGoalIndex(unsigned int _goal_index);
		int getPopulationSize();
		void welcomeNewMember(Sentient_Entity a);
		int getQuantityByItem(Item i);
		int getTribeSize();

		void addItemToStock(Item i, int quantity);
		~Tribe();

	private:
		unsigned int id;
		std::string name;
		unsigned int goal_index;
};

#endif
