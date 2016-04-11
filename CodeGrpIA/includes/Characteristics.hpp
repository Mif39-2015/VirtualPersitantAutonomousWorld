#ifndef CHARACTERISTICS_HPP
#define CHARACTERISTICS_HPP

#include <vector>


class Characteristics{

public:

	//les characteristiques provenant du fichier
	static std::vector<Characteristics> listCharacteristics;
	
	//cnstruit un vector de charactéristiques à partir du fichier donné
	std::vector<Characteristics> loadCharacteristics(std::string fileName);


	int getId();
	int getMin();
	int getMax();
	std::string getName();
	std::string getDefinition();
	int getPrecision();
	
	void setId(int i);
	void setMin(int m);
	void setMax(int m);
	void setName(std::string n);
	void setDefinition(std::string d);
	void setPrecision(int p);
	
	
	
private:
	int id;
	int min;
	int max;
	std::string name;
	std::string definition;
	int precision;



};




#endif
