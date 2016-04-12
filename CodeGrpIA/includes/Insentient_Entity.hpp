#ifndef INSENTIENT_ENTITY_HPP
#define INSENTIENT_ENTITY_HPP

#include "Tangible_Entity.hpp"
#include "Vector3.hpp"
#include "Characteristics.hpp"

class Insentient_Entity : public Tangible_Entity{
    public:
        Vector3 sizeIE;
        Insentient_Entity(std::string n, std::string tid, int o, int x, int y, int z);
        int getOrientation();
        void setOrientation(int _o);
        unsigned int getStructuralPoint();
        void setStructuralPoint(unsigned int sp);
        int getValById(int id);
        int setValById(int id, int v);
	protected:
        static unsigned int idCount;
        int orientation;
        unsigned int structural_point;
        std::map<int, int> characteristics;
};

#endif
