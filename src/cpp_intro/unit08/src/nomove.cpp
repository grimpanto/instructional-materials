#include <iostream>  // nomove.cpp
using namespace std;

class Distance {
    double len;
  public:
    Distance()=default;
    Distance(double len)
      : len{len} { cout << "ctor: " << len << endl; }
    Distance(const Distance& other) : len{other.len} {
        cout << "copy ctor: " << len << endl;
    }
    Distance(Distance&& other) = delete;
    ~Distance() { cout << "dstor" << endl;  }
};

Distance one(int n) {
    Distance tmp1{1};  Distance tmp2{2};
    if (n > 2) return tmp1;  else return tmp2;  }
int main() {  Distance d1{one(1)};
              Distance d2=one(3);  }
