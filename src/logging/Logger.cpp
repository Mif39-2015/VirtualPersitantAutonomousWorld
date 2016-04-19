/**
 * \file Logger.cpp
 * \brief Implementation of Logger.hpp
 */
#include "logging/Logger.hpp"


Logger::Logger(const string& _fileName) :
fileName(_fileName)
{
	file.open(fileName);
}

Logger::~Logger()
{
	file.close();
}
bool Logger::log(const string& text){
	if (file.is_open()) {
		file << text << endl;
		return true;
	} else {
		return false;
	}
}

ostream& Logger::operator<<(const string& text){
    this->log(text);
}
