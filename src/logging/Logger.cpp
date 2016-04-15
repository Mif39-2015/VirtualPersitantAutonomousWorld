/**
 * \file Logger.cpp
 * \brief Implementation of Logger.hpp
 */
#include "Logger.hpp"


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
		file << text;
		return true;
	} else {
		return false;
	}        
}

bool Logger::logLine(const string& text){
	if (this->log(text)) {
		file << endl;
		return true;
	} else {
		return false;
	}
}

ostream& Logger::operator<<(const string& text){
    this->logLine(text);
}
