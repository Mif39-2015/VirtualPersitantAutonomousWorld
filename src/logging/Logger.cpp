/**
 * \file Logger.cpp
 * \brief Implementation of Logger.hpp
 */
#include "Logger.hpp"


Logger::Logger(string _fileName) :
fileName(_fileName)
{
	file.open(fileName);
}

Logger::~Logger()
{
	file.close();
}

void Logger::log(string text){
	if (file.is_open()) {
		file << text;
	}
}

void Logger::logLine(string text){
	if (file.is_open()) {
		file << text << endl;
	}
}

ostream& Logger::operator<<(string text){
	this->logLine(text);
}
