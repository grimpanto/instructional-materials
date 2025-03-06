
#include <iostream>
#include <cmath>  // -> M_PI

using namespace std;

int main() {
    double b{0.1};
    double a{M_PI};
    double t{1};
    cout << M_PI << endl; // 3.14159
    cout << (a + t * (b - a)) << endl;  // 0.1
    cout << (a + t * (b - a) == b) << endl;  // 0
}
