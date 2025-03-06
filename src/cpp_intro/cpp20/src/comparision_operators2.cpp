#include <iostream> // comparision_operators2.cpp
struct Pair {  // comparing lexicographically!
    int a{1};  int b{2};

    bool operator<(const Pair& other) const {
        return a < other.a || a == other.a &&
          b < other.b; }
    bool operator==(const Pair& other) const {
        return a == other.a && b == other.b; }
    bool operator!=(const Pair& other) const {
        return !(*this == other); }
    bool operator<=(const Pair& other) const {
        return *this == other || *this < other; }
    bool operator>(const Pair& other) const {
        return other < *this; }
    bool operator>=(const Pair& other) const {
        return *this == other || *this > other;
    }
};

using namespace std;

int main() {
    Pair p1;
    Pair p2{.b=3};
    cout << (p1 == p2) << endl;  // 0
    cout << (p1 != p2) << endl;  // 1
    cout << (p1 < p2) << endl;  // 1
    cout << (p1 <= p2) << endl;  // 1
    cout << (p1 > p2) << endl;  // 0
    cout << (p1 >= p2) << endl;  // 0
}
