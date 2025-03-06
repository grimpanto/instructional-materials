#include <iostream>  // structs.cpp
using namespace std;

struct Circle {
    double r{1};
    double x{};
    double y;
};

int main() {
    Circle c;  // it's a "POD" (plain old data type)!
    // therefore, no initialization!
    cout << c.r <<  ' ' << c.x << ' ' << c.y << endl;
    c = Circle{3, 2, 1};
    cout << c.r <<  ' ' << c.x << ' ' << c.y << endl;
}
