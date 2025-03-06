#include <iostream>  // structs2.cpp
using namespace std;

// convention: use struct for simple aggregates
struct Point {
    double x;
    double y;
};

int main() {
    Point p{};// also a POD but initialized explicitly
    cout << p.x <<  ' ' << p.y << endl;
    Point points[]{{}, {1, 1}, {2, {}}};
    cout << points[0].x <<  ' ' << points[1].x << ' '
      << points[2].x << endl;
}
