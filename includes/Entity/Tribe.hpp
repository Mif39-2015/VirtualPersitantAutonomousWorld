#ifndef TRIBE_HPP
#define TRIBE_HPP

#include "Entity/Entity.hpp"
// #include "Goal.hpp" //Uncomment when Goal is implemented
#include "Item.hpp"
// #include "Complex_Behavior.hpp" //Uncomment when Complex_Behavior is implemented

#include <string>
#include <map>
#include <vector>

class Tribe : public Entity{
	private:
		unsigned int id;
		std::string name;
		unsigned int goal_index;

	public:
		//Uncomment when Agent, Goal and Complex_Behavior are implemented
		// std::vector<Goal> goal_list;
		// std::map<Complex_Behavior, int> job_repartition;

		/*
		* C'est l'ensemble de tous les entités dans le clan
		* */
		std::vector<Entity> tribe;

		std::map<Item, int> stock;

		Tribe(unsigned int, std::string, unsigned int, type);
		unsigned int getId();
		std::string getName();
		unsigned int getGoalIndex();

		void setId(unsigned int _id);
		void setName(std::string _n);
		void setGoalIndex(unsigned int _goal_index);

		int getPopulationSize();
		int getNbBuildings();
		int getNbRessources();

		void addNewEntity(Entity a);
		int getQuantityByItem(Item i);
		int getTribeSize();

		void addItemToStock(Item i, int quantity);
		~Tribe();

};

#endif
