#include <iostream>  // defaultargs.cpp
using namespace std;

int getDefault() { return 0; }

// will be evaluated at runtime; =0 also possible
int incr(int counter=getDefault()) {
    return counter + 1;
}
int main() {
    cout << incr() << ' ';
    cout << incr(1) << endl;
}
