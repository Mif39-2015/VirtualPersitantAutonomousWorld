#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <string>
#include <map>

using namespace std;
        enum type{
            ID_AGENT,
            ID_ANIMAL,
            ID_BUILDING,
            ID_RESSOURCE,
            ID_ITEM,
            ID_TRIBE
        };
class Entity{

	protected:

		static unsigned int idCount;
		unsigned int id;
		type typeId;
		string name;
		bool modif;

	public:

        Entity(std::string,type);

		unsigned int getId();
		string getName();
		bool getModif();
		type getTypeId();
		void setModif(bool m);
		void setName(std::string n);

		~Entity(void);
};

#endif
