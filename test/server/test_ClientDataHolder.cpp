#include "serveur_catch.hpp"
#include "server/ClientDataHolder.hpp"

#include <iostream>

TEST_CASE("Test ClientDataHolder", "[run]")
{
    ClientDataHolder cdh = ClientDataHolder();
	string popups = PATH_DATA"/popups.txt";
    cdh.addFileToList(popups);
    REQUIRE(cdh.getFilesList().size() == 1);
    REQUIRE(cdh.getFilesList()[0] == popups);
}
