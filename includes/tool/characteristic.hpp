#ifndef CHARACTERISTIC_HPP
#define CHARACTERISTIC_HPP

#include <string>
#include <iostream>
#include <cstdio>

class Characteristic{
public:
    //Ctor
    Characteristic();
    Characteristic(int i, int mi, int ma, std::string n, std::string d, int p) : id(i),vmin(mi),vmax(ma),name(n),definition(d),precision(p){};

    //Getters
    int getId();
    int getMin();
    int getMax();
    std::string getName();
    std::string getDefinition();
    int getPrecision();

    //Setters
    void setId(int i);
    void setMin(int m);
    void setMax(int m);
    void setName(std::string n);
    void setDefinition(std::string d);
    void setPrecision(int p);

    //Dtor
    ~Characteristic(){};

private:
    int id; //ID de la carac
    int vmin; //La valeur minimum de la carac
    int vmax; //La valeur maximum de la carac
    std::string name; //Le nom de la carac
    std::string definition; //Une description de la carac (principalement pour Interface)
    int precision; //La précision de la carac : la valeur de la carac va etre x/precision (C'est pour l'IA)
};

#endif
