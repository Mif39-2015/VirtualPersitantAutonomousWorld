#include "serveur_catch.hpp"
#include "logging/Logger.hpp"

#include <iostream>

#include <boost/log/trivial.hpp>

TEST_CASE("Test Logger", "[log]")
{
    BOOST_LOG_TRIVIAL(debug) << "A debug severity message";
    BOOST_LOG_TRIVIAL(info) << "An informational severity message";
    BOOST_LOG_TRIVIAL(warning) << "A warning severity message";
    BOOST_LOG_TRIVIAL(error) << "An error severity message";
    BOOST_LOG_TRIVIAL(fatal) << "A fatal severity message";

    /*
        Logger log("logfile.log");
        log.log("first text");
        log << "third text";
    */
}
