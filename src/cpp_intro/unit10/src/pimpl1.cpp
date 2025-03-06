#include <iostream>  // pimpl1.cpp
using namespace std;
class Accumulator {
  public:
    Accumulator(double init=0) : val{init} {}
    double value() { return val; }
    Accumulator& operator+=(double v) {
        val += v;
        return *this;
    }
    void reset() { val = 0; }
  private:
    double val;
};
int main() {
    Accumulator acc;
    acc += 2;
    acc += 40;
    cout << acc.value() << endl;
}
