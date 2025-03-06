#include <iostream>  // designated_initializers.cpp

struct Point3D {
    int x;
    int y{1};
    int z;
};

using namespace std;

int main() {
    Point3D p1{.x=1, .z=3};  // order matters
    cout << p1.x << ", " << p1.y << ", "
         << p1.z << endl;  // 1, 1, 3
    
    Point3D p2{.y=2, .z=3};  // x will be initialized!
    cout << p2.x << ", " << p2.y << ", "
         << p2.z << endl;  // 0, 2, 3
}
