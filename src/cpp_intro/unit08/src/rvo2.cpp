#include <iostream>  // rvo2.cpp
using namespace std;
class Distance {
    double len{};
  public:
    Distance(double len)
      : len{len} { cout << "ctor" << endl; }
    Distance(const Distance& other) : len{other.len} {
        cout << "copy ctor" << endl;  }
    ~Distance() {  cout << "dtor" << endl;  }  };
Distance one() {
    Distance res{1};
    return res; }
int main() { Distance d2{one()};
             Distance d3=one();  }
