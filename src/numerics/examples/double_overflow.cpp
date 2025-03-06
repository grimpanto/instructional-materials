
#include <iostream>
#include <limits>
#include <cmath>

using namespace std;

int main() {
    double x{};
    x = numeric_limits<double>::max();
    cout << x << " is infinite: " << isinf(x) << endl;
    x = numeric_limits<double>::infinity();
    cout << x << " is infinite: " << isinf(x) << endl;
    cout << x + 1 << endl;
}
