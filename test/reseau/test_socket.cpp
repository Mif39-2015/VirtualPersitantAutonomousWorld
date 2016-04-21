#include "serveur_catch.hpp"
#include "reseau/NetworkAdapter.hpp"

#include <iostream>

TEST_CASE("Test socket", "[foo]")
{
    NetworkAdapter netAd(NULL);
    netAd.Init(10);

    netAd.Run();

}
