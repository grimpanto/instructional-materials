#include <iostream>  // bool.cpp
using namespace std;
int main() {
    cout << true << endl; // 1
    cout << false << endl;  // 0
    cout << boolalpha;  // yet another I/O manip.
    cout << true << endl; // true
    cout << false << endl;  // false
    cout << noboolalpha << true << endl;  // 1
    cout << false << endl;  // 0
    cout << true + 1 << endl;  // 2
    cout << (true & 3) << endl;  // 1
}
