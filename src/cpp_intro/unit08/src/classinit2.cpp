#include <iostream>  // classinit2.cpp
using namespace std;

class Distance {
    double len;
  public:
    Distance() : Distance{0} {} // delegating cons!
    Distance(double len) : len{len} {
        cout << this->len;
    } };
int main() {
    Distance d1;
    Distance d2{1};  // direct init
    Distance d3={2};  // copy init (same as: d3=2)
}
