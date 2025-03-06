#include <iostream>  // deprecated.cpp
using namespace std;

[[deprecated]] int f() { return 1; }

[[deprecated("g() is legacy; use h() instead")]]
int g() { return 2; }

int h() { return 3; }

int main() {
    cout << g() << endl;  // warning!
}
