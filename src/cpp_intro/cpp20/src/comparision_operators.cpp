#include <iostream>  // comparision_operators.cpp
struct Int {
    int v;
    Int(int v=0) : v{v} {}

    bool operator<(const Int& other) const {
        return v < other.v; }
    bool operator==(const Int& other) const {
        return v == other.v; }
    bool operator!=(const Int& other) const {
        return !(*this == other); }
    bool operator<=(const Int& other) const {
        return *this == other || *this < other; }
    bool operator>(const Int& other) const {
        return other < *this; }
    bool operator>=(const Int& other) const {
        return *this == other || *this > other;
    } };

using namespace std;

// then it could be used like this:
int main() {
    Int i1;
    Int i2{2};
    cout << (i1 == i2) << endl;  // 0
    cout << (i1 != i2) << endl;  // 1
    cout << (i1 < i2) << endl;  // 1
    cout << (i1 <= i2) << endl;  // 1
    cout << (i1 > i2) << endl;  // 0
    cout << (i1 >= i2) << endl;  // 0

    // wrong order in C++17:
    //cout << (0 == i1) << endl;
    // -> additional operators and friends have
    //    to be defined
}
