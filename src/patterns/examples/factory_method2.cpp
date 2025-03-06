
#include <iostream>
#include <cmath>

using namespace std;

struct Point {
    float x;
    float y;
    // Point(float x, float y) {}
    // Point(float r, float alpha) {}
 protected:
    Point(float x, float y) : x{x}, y{y} {}
  public:
    static Point create_cartesian(float x, float y) {
        return { x, y };
    }
    static Point create_polar(float r, float alpha) {
        return { r * cos(alpha), r * sin(alpha) };
    }
};

int main() {
    Point p{Point::create_polar(1, atan(1))};
    cout << p.x << ' ' << p.y << endl;
}
