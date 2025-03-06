#include <iostream>  // rvo3.cpp
using namespace std;
class Distance {
    double len{};
  public:
    Distance(double len)
      : len{len} { cout << "ctor" << endl; }
    Distance(const Distance& other) : len{other.len} {
        cout << "copy ctor" << endl;  }
};
void one(Distance d) {
    cout << "inside one" << endl; }
int main() {
    one(Distance{1});
}
