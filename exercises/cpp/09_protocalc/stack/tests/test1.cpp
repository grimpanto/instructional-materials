// @copyright 2019 Günter Kolousek

#include "stack.h"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

TEST_CASE("is an empty stack really empty()?") {
    Stack stack;
    CHECK(stack.empty());
}

TEST_CASE("is an non-empty stack really not empty()?") {
    Stack stack;
    stack.push(1);
    CHECK(!stack.empty());
}

TEST_CASE("pop from empty stack") {
    Stack stack;

    CHECK_THROWS_AS(stack.pop(), domain_error);
}

TEST_CASE("pop after push") {
    Stack stack;

    stack.push(1);
    CHECK(stack.pop() == 1);
    stack.push(3);
    stack.push(2);
    stack.push(1);
    CHECK(stack.pop() == 1);
    CHECK(stack.pop() == 2);
    CHECK(stack.pop() == 3);
}

TEST_CASE("top of empty stack") {
    Stack stack;

    CHECK_THROWS_AS(stack.top(), domain_error);
}

TEST_CASE("top after push") {
    Stack stack;

    stack.push(3);
    CHECK(stack.top() == 3);
    stack.push(2);
    CHECK(stack.top() == 2);
    stack.push(1);
    CHECK(stack.top() == 1);
}

TEST_CASE("top, pop and push") {
    Stack stack;

    stack.push(3);
    stack.push(2);
    stack.push(1);
    double top_elem{stack.top()};
    double popped_elem{stack.pop()};
    CHECK(top_elem == popped_elem);
    stack.push(popped_elem);
}


TEST_CASE("initialization with exactly one value") {
    Stack s{1};
    CHECK(!s.empty());
    CHECK(s.top() == 1);
    CHECK(s.pop() == 1);
    CHECK(s.empty());
}


TEST_CASE("constant objects") {
    const Stack s(1);
    CHECK(!s.empty());
    CHECK(s.top() == 1);
}


TEST_CASE("initialization with several values") {
    Stack s{1, 2, 3};
    CHECK(!s.empty());
    CHECK(s.pop() == 3);
    CHECK(s.pop() == 2);
    CHECK(s.pop() == 1);
    CHECK(s.empty());
}
