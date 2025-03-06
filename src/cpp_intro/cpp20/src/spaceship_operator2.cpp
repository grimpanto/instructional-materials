#include <iostream>  // spaceship_operator2.cpp
using namespace std;

struct Pair {
    int a{1};  int b{2};
    // also, generates operators for: ==, !=
    auto operator<=>(const Pair&) const=default; };

int main() {
    Pair p1;  Pair p2{.b=3};
    cout << (p1 == p2) << endl;  // 0
    cout << (p1 != p2) << endl;  // 1
    cout << (p1 < p2) << endl;  // 1
    cout << (p1 <= p2) << endl;  // 1
    cout << (p1 > p2) << endl;  // 0
    cout << (p1 >= p2) << endl;  // 0
    cout << (p1 <=> p2 < 0) << endl;  // 1
    cout << (p1 <=> p2 == 0) << endl;  // 0
    cout << (p1 <=> p2 > 0) << endl;  // 0
}
