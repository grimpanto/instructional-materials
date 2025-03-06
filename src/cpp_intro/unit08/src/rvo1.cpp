#include <iostream>  // rvo1.cpp
using namespace std;
class Distance {
    double len{};
  public:
    Distance(double len)
      : len{len} { cout << "ctor" << endl; }
    Distance(const Distance& other) : len{other.len} {
        cout << "copy ctor" << endl;  }
    ~Distance() {  cout << "dtor" << endl;  }  };
Distance one() { return Distance{1}; }
int main() {
    Distance d2{one()};  // direct init
    Distance d3=one();  // copy init
}
