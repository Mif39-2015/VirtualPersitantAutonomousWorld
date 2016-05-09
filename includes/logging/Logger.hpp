/**
 * \file Logger.hpp
 * \brief Logger class definition
 */
#ifndef _LOGGER_
#define _LOGGER_

#include <iostream>
#include <fstream>

#include <boost/log/trivial.hpp>

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
    Logger(const string& _fileName);
    ~Logger();
    bool log(const string& text);
    ostream& operator<<(const string& text);
};

#endif
