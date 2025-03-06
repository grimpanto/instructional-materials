#include <iostream>  // inline.cpp
using namespace std;

inline double square(double x) {
    return x * x;
}

constexpr double add(double a, double b) {
    return a + b;
}  // implicitly inline

int main() {
    // probably no function call at all!
    cout << "2^2 = " << square(2) << endl;
}
