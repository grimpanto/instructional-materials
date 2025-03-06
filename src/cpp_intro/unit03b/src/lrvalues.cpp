#include <iostream>  // lrvalues.cpp
using namespace std;

int x{0};

int f() { return 0; }
// never ever should be x a local variable...
int& g() { return x; }

int main() {
    // f() = 2;  // error: lvalue required...
    g() = 1;
    cout << x << endl;
}
