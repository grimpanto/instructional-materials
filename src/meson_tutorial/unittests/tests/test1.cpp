
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "fact.h"

TEST_CASE("Factorials are computed", "[factorial]") {
    REQUIRE(fact(0) == 1);
    REQUIRE(fact(1) == 1);
    REQUIRE(fact(2) == 2);
    REQUIRE(fact(3) == 6);
    REQUIRE(fact(10) == 3628800);
}
