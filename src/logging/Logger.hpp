/**
 * \file Logger.hpp
 * \brief Logger class definition
 */
#ifndef _LOGGER_
#define _LOGGER_

#include <iostream>
#include <fstream>

using namespace std;

/**
 * \class Logger
 * \brief Loggs world changes, network activity and AI states
 */
class Logger {
	private:
		string fileName;
		ofstream file;
	public:
		Logger(string _fileName);
		~Logger();
		void log(string text);
		void logLine(string text);
		ostream& operator<<(string text);
};

#endif
