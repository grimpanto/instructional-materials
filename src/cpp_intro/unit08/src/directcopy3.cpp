#include <iostream>  // directcopy3.cpp
#include <initializer_list>
using namespace std;
class Distance {
    double len{};
  public:
    Distance(double len)
      : len{len} { cout << "ctor" << endl; }
    Distance(initializer_list<double> l)
      : len{*l.begin()} {
        cout << "initializer ctor" << endl;  }
    ~Distance() { cout << "dtor" << endl; }  };
int main() {
    Distance d1{1};  Distance d2 = {1};  }
