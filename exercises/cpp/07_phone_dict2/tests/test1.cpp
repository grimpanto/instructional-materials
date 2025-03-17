// @copyright 2019 Günter Kolousek

#include "sll.h"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

TEST_CASE("insert in sll") {
    List lst;

    int tmp;
    CHECK(lst.search("xxx", tmp) == false);
    CHECK(lst.set("xxx", 111));
    CHECK(lst.search("xxx", tmp));
    CHECK(tmp == 111);
}

TEST_CASE("search in sll") {
    List lst;

    int tmp;
    CHECK(lst.search("xxx", tmp) == false);
    CHECK(lst.set("xxx", 111));
    CHECK(lst.set("yyy", 222));
    CHECK(lst.search("xxx", tmp));
    CHECK(tmp == 111);
    CHECK(lst.search("yyy", tmp));
    CHECK(tmp == 222);
}

TEST_CASE("remove in sll") {
    List lst;

    int tmp;
    CHECK(lst.set("zzz", 333));
    CHECK(lst.set("yyy", 222));
    CHECK(lst.set("xxx", 111));
    CHECK(lst.remove("zzz"));
    CHECK(lst.search("zzz", tmp) == false);
    CHECK(lst.remove("xxx"));
    CHECK(lst.search("xxx", tmp) == false);
    CHECK(lst.remove("yyy"));
    CHECK(lst.search("yyy", tmp) == false);
}
