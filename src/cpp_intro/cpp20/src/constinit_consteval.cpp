#include <iostream>  // constinit_consteval.cpp
using namespace std;

// will be evaluated at compile time!
consteval int calc_area(double a) { return a * a; }

// will be initialized at compile time!
//   *must* have static storage duration
//          *or* thread storage duration
constinit double area{calc_area(3)};

int main() {
    cout << calc_area(10) << endl;
    cout << area << endl;
    // thread local vars have thread storage duration
    constinit thread_local double area2{calc_area(3)};
    area = 42; // may be altered... if not desired then
    cout << area << endl; // add 'const' to definition
}
