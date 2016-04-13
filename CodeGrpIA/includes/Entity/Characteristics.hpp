#ifndef CHARACTERISTICS_HPP
#define CHARACTERISTICS_HPP

#include <vector>
#include <iostream>

class Characteristics{

	public:
		int getId();
		int getMin();
		int getMax();
		std::string getName();
		std::string getDefinition();
		std::string getType();
		int getPrecision();

		void setId(int i);
		void setMin(int m);
		void setMax(int m);
		void setName(std::string n);
		void setDefinition(std::string d);
		void setType(std::string t);
		void setPrecision(int p);

		friend std::ostream & operator<<(std::ostream & os, Characteristics const & obj){
		    // write obj to stream
			os << obj.id << std::endl;
			os << obj.name << std::endl;
			os << obj.type << std::endl;
			os << obj.definition << std::endl;
			os << "Between " << obj.min << " and " << obj.max << std::endl;
		    return os;
		}

	private:
		int id;
		int min;
		int max;
		std::string name;
		std::string definition;
		std::string type;
		int precision;
	};

class CharacteristicsList{

public:
        //les characteristiques provenant du fichier
	static std::vector<Characteristics> listCharacteristics;

	//cnstruit un vector de charactéristiques à partir du fichier donné
	static int loadCharacteristicsFile(std::string fileName);

};





#endif
