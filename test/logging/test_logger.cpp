#include "serveur_catch.hpp"
#include "logging/Logger.hpp"

#include <iostream>

TEST_CASE("Test Logger", "[log]")
{
    Logger log("logfile.log");
    log.log("first text");
    log << "third text";
}
