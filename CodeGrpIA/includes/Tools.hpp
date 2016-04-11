#ifndef TOOLS_HPP
#define TOOLS_HPP

#include <ctime>
#include <iomanip>
#include <limits>
#include <cstdlib>

template<typename T>
T rand(T min, T max){
	srand (std::time(0) + (int)(rand()*10));

	return min + (T)rand()/((T)RAND_MAX/(T)(max-min));
}

std::string getRandomMaleName();
std::string getRandomFemaleName();

#endif