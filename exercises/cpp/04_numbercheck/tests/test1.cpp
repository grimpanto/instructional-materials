// @copyright 2019 Günter Kolousek

#include "numbercheck.h"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <iostream>
#include <vector>

using namespace std;

TEST_CASE("correct integer numbers without exponent") {
    numbercheck::FloatingPointChecker fpc;
    CHECK(fpc.check("0"));
    CHECK(fpc.check("-0"));
    CHECK(fpc.check("0123"));
    CHECK(fpc.check("+123"));
    CHECK(fpc.check("-123"));
}

TEST_CASE("correct integer numbers with exponent") {
    numbercheck::FloatingPointChecker fpc;
    CHECK(fpc.check("+0e0"));
    CHECK(fpc.check("0e0"));
    CHECK(fpc.check("0123e+1"));
    CHECK(fpc.check("+123e-111"));
    CHECK(fpc.check("-123e11"));
}

TEST_CASE("correct floating point numbers without exponent") {
    numbercheck::FloatingPointChecker fpc;
    CHECK(fpc.check(".1"));
    CHECK(fpc.check("1.1"));
    CHECK(fpc.check("0.123"));
    CHECK(fpc.check("+12.23"));
    CHECK(fpc.check("-.123"));
}

TEST_CASE("correct floating point numbers with exponent") {
    numbercheck::FloatingPointChecker fpc;
    CHECK(fpc.check(".1e0"));
    CHECK(fpc.check("1.1e11"));
    CHECK(fpc.check("0.123e+123"));
    CHECK(fpc.check("+12.23e-123"));
    CHECK(fpc.check("-.123e11"));
}

TEST_CASE("false numbers") {
    numbercheck::FloatingPointChecker fpc;
    CHECK(!fpc.check("+"));
    CHECK(!fpc.check("-."));
    CHECK(!fpc.check("0e"));
    CHECK(!fpc.check("0.e"));
    CHECK(!fpc.check("0.e+"));
    CHECK(!fpc.check("0.1e-"));
    CHECK(!fpc.check("2.a"));
}
