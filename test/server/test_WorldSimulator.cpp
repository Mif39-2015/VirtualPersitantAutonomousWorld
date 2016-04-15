#include "serveur_catch.hpp"
#include "server/WorldSimulator.hpp"

#include <iostream>

TEST_CASE("Test WorldSimulator", "[run]")
{
    WorldSimulator simulator = WorldSimulator();

    simulator.run(false);
}
