#ifndef _STRINGTOOL_
#define _STRINGTOOL_
#include <string>
#include <sstream>
#include <vector>

class StringTool {
	public:
		static std::vector<std::string>& split(const std::string &s, char delim, std::vector<std::string> &elems);
		static std::vector<std::string> split(const std::string &s, char delim);
};

#endif
