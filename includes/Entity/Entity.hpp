#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <string>
#include <map>

#include "../../src/tool/cJSON.hpp"

using namespace std;

enum type{
	ID_AGENT,
	ID_ANIMAL,
	ID_BUILDING,
	ID_RESSOURCE,
	ID_ITEM,
	ID_TRIBE
};

static const char* TypeNames[] = { 
	"ID_AGENT", 
	"ID_ANIMAL", 
	"ID_BUILDING", 
	"ID_RESSOURCE", 
	"ID_ITEM", 
	"ID_TRIBE" 
};
class Entity{

	protected:

		static unsigned int idCount;
		unsigned int id;
		type typeId;
		string name;
		std::map<int, int> charact_correspondence; /*!<correspondance entre la caracteristique et le sentient entity.*/
		bool modif;

	public:

        Entity(std::string,type,std::map<int, int> charac);

		unsigned int getId();
		string getName();
		bool getModif();
		type getTypeId();
		void setModif(bool m);
		void setName(std::string n);
		
		/*!
		* Renvoie la valeur de la clé id de la map.
		* Si la clé existe, sa valeur associée est renvoyée, sinon -1
		* */
		int getVal(int id);

		/*!
		* Met à jour la valeur associée à la clé id si cette derniere
		* existe bien dans la map et renvoie 1 (success) sinon renvoie -1
		* */
		int setVal(int id, int v);
		
		cJSON* toJson();

		~Entity(void);
};

#endif
