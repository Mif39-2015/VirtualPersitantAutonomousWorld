#include <vector>
#include <cstdlib>
#include "pugixml.hpp"
#include "characteristic.hpp"

std::vector<Characteristic> parseCharacteristics(const char* docname);
// pour utiliser :
//static std::vector<Characteristic> listCharacteristics = parseCharacteristics("src/carac.xml");
