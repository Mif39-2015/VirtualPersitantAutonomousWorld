#ifndef CHARACTERISTICS_HPP
#define CHARACTERISTICS_HPP

#include <vector>

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



	private:
		int id;
		int min;
		int max;
		std::string name;
		std::string definition;
		std::string type;
		int precision;
	};
	
enum characs{
	C_VITALITY           = 0,
	C_GENDER             = 1,
	C_AGE  	             = 2,
	C_AGRESSIVENESS      = 3,
	C_FITNESS            = 4,
	C_SATIETY            = 5,
	C_SATIETY_THRESHOLD  = 6,
	C_REFLEX             = 7,
	C_PERCEPTION         = 8,
	C_INDEPENDENCE       = 9,
	C_CHARISMA           = 10,
	C_CAPACITY           = 11,
	C_STAMINA            = 12,
	C_STAMINA_THRESHOLD  = 13,
	C_SANITY             = 14,
	C_RESPAWN_RATE       = 15,
	C_RESPAWN_VALUE      = 16,
	C_ORIENTATION        = 17,
	C_STRUCTURAL_POINT   = 18,
	C_WEIGHT             = 19
};

class CharacteristicsList{

public:
    	//les characteristiques provenant du fichier
	static std::vector<Characteristics> listCharacteristics;

	//cnstruit un vector de charactéristiques à partir du fichier donné
	static int loadCharacteristicsFile(std::string fileName);

};


#endif
