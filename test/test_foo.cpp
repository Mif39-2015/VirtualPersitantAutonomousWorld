#include "serveur_catch.hpp"
#include "foo.hpp"

#include <iostream>

TEST_CASE("Test foo", "[foo]")
{
    Foo a;

    REQUIRE(a.bar == 5);
}
