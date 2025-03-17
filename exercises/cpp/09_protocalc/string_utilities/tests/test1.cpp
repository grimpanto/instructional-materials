
#include "string_utilities.h"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

TEST_CASE("split an string without delimiter") {
    string s;
    CHECK(split(s, ',').size() == 0);
    s = "abc def ghi";
    CHECK(split(s, ',').size() == 1);
}


TEST_CASE("split an string with exactly one delimiter") {
    string s{","};
    CHECK(split(s, ',').size() == 1);
    s = "abc def, ghi";
    CHECK(split(s, ',').size() == 2);
}


TEST_CASE("split an string with exactly two delimiters") {
    string s{",,"};
    CHECK(split(s, ',').size() == 2);
    s = "abc, def, ghi";
    CHECK(split(s, ',').size() == 3);
}
