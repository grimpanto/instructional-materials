#include <iostream>  // lambdaexpr17.cpp
#include <algorithm>
#include <memory>

using namespace std;

struct X {
    int i{42};
    int f() {
        // implicitly capturing of this using [=]
        // is deprecated since C++20, you will get a warning!
        // return [=]{ return i; }();
        return [*this]{ return i; }();
    }
};

int main() {
    X x;
    cout << x.f() << endl;  // -> 42
}
