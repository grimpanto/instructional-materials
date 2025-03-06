#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include <iostream>

#include "calc.h"

int sum(int a, int b) {
    return a + b;
}

TEST_CASE("sums are computed", "[arithmetic]") {
    REQUIRE(sum(0, 0) == 0);
    REQUIRE(sum(2, 3) == 5);
    REQUIRE(sum(3, 2) == 5);
    //...
}    
