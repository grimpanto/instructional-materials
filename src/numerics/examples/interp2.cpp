
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    {
    double a{-16.0e30};
    double b{16};
    double t{1};
    cout << setprecision(std::numeric_limits<long double>::digits10 + 1);
    cout << t * b + (1.0 - t) * a << endl;  // 0.1
    //cout << t * b + (1 - t) * a << endl;  // 0.1
    cout << a + t * (b - a) << endl;
    }

    {
    double a{0.45};
    double b{0.45};
    double t{0.81965185546875};
    cout << setprecision(std::numeric_limits<long double>::digits10 + 1);
    cout << t * b + (1.0 - t) * a << endl;  // 0.1
    //cout << t * b + (1 - t) * a << endl;  // 0.1
    cout << ((b - a) == 0) << endl;
    cout << a + t * (b - a) << endl;
    cout << (a + t * (b - a) == a) << endl;
    cout << a << endl;
    }

}
