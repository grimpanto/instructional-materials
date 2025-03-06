#include <iostream>  // spaceship_operator.cpp
using namespace std;

struct Pair {
    int a{1};  int b{2};
    auto operator<=>(const Pair& other) const {
       if (auto compare{a <=> other.a}; compare != 0)
           return compare;
       return b <=> other.b;
    }  // generates operators for: <, <=, >, >=
    bool operator==(const Pair& other) const {
        return (*this <=> other) == 0;
    }  // has to be defined separately!
    // since C++20: operator!= has not to be defined
    //   anymore...
};

int main() {
    Pair p1;  Pair p2{.b=3};
    cout << (p1 == p2) << endl;  // 0
    cout << (p1 != p2) << endl;  // 1
    cout << (p1 < p2) << endl;  // 1
    cout << (p1 <= p2) << endl;  // 1
    cout << (p1 > p2) << endl;  // 0
    cout << (p1 >= p2) << endl;  // 0
    // will be implicitely converted and
    // order does not matter:
    cout << ({1, 2} > p2) << endl;

    // may be compared against 0!
    //   (though it is not a number!)
    cout << (p1 <=> p2 < 0) << endl;  // 1
    cout << (p1 <=> p2 == 0) << endl;  // 0
    cout << (p1 <=> p2 > 0) << endl;  // 0
}
