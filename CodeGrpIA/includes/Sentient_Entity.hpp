#ifndef SENTIENT_ENTITY_HPP
#define SENTIENT_ENTITY_HPP

#include <string>
#include <map>

#include "Entity.hpp"

class Sentient_Entity : public Entity{

	public:

		Sentient_Entity(int, bool, int, int , int ,int, int , int, int, unsigned int, std::string);
//------------------ Accesseurs -----------------------------------------
		int getVitality();
		bool getGender();
		int getAge();
		int getAgressiveness();
		int getFitness();
		int getSatiety();
		int getSatietyTreshold();
		int getReflex();
		int getPerception();
//---------------- Mutateurs --------------------------------------------
        void setVitality(int v);
        void setGender(bool g);
        void setAge (int a);
        void setAgressiveness(int ag);
        void setFitness(int f);
        void setSatiety(int s);
        void setSatietyTreshold(int st);
        void setReflex (int r);
        void setPerception (int p);

        bool isHungry();
        bool isAgressive();
		//destructor ?

	protected:
		int vitality;
		bool gender;
		int age;
		int agressiveness;
		int fitness;
		int satiety;
		int satiety_threshold;
		int reflex;
		int perception;
		//Complex_Behaviour job;



};

#endif
