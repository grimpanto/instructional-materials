#include <iostream>  // spaceship_operator5.cpp
using namespace std;
struct Int {
    int v;
    Int(int v=0) : v{v} {}
    strong_ordering operator<=>(const Int& other) const {
        return v <=> other.v; }
    bool operator==(const Int& other) const {
        return (v == other.v); } };
int main() {
    Int i1{42};  int i2{7};
    cout << (i1 == i2) << endl;  // 0
    cout << (i1 != i2) << endl;  // 1
    cout << (i1 < i2) << endl;  // 0
    cout << (i1 <= i2) << endl;  // 0
    cout << (i1 > i2) << endl;  // 1
    cout << (i1 >= i2) << endl;  // 1
    // order does not matter anymore:
    cout << (7 < i2) << endl;  // 0
}
