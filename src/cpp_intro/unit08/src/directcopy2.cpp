#include <iostream>  // directcopy2.cpp
using namespace std;
class Distance {  double len;
  public:
    Distance()=default;
    explicit Distance(double len)
      : len{len} { cout << "ctor" << endl; }
    Distance(const Distance& other) : len{other.len} {
        cout << "copy ctor" << endl;  }
    ~Distance() { cout << "dstor" << endl; }  };
int main() {
    Distance d1;
    Distance d2{1};  // direct init
    // copy init -> compiler error because of explicit
    // Distance d3 = 2;
} // C++17: *no* output of "copy ctor"
