/*#include <iostream>
#include <sstream>
#include "Agent.hpp"

unsigned int Agent::idCount = 0;

Agent::Agent(int ind, int c, int cap, int st, int st_t, int san, int v, bool g, int a, int agr, int f, int s, int s_t, int r, int p, std::string n)
	:Sentient_Entity(v, g, a, agr, f, s, s_t, r, p, n), independence(ind), charisma(c), capacity(cap), stamina(st), stamina_threshold(st_t), sanity(san)
{
	std::stringstream ss;
	ss << "ag_" << Agent::idCount;
	id = ss.str();
	std::cout << id << std::endl;
	Agent::idCount++;
	//intialization of memory
}

Agent::~Agent(void){}

//------------------ Accesseurs -----------------------------------------
unsigned short int Agent::getIndependence() {
	return independence;
}

unsigned short int Agent::getCharisma() {
	return charisma;
}

unsigned short int Agent::getCapacity() {
	return capacity;
}

unsigned short int Agent::getStamina() {
	return stamina;
}

unsigned short int Agent::getStamina_threshold() {
	return stamina_threshold;
}

unsigned short int Agent::getSanity() {
	return sanity;
}

//---------------- Mutateurs --------------------------------------------
void Agent::setIndependence(int i) {
	if (i >= 0)
		independence = i;
}

void Agent::setCharisma(int c) {
	if (c >= 0)
		charisma = c;
}

void Agent::setCapacity(int c) {
	if (c >= 0)
		capacity = c;
}

void Agent::setStamina(int s) {
	if (s >= 0)
		stamina = s;
}

void Agent::setStamina_threshold(int s) {
	if (s >= 0)
		stamina_threshold = s;
}

void Agent::setSanity(int s) {
	if (s >= 0)
		sanity = s;
}

*/
