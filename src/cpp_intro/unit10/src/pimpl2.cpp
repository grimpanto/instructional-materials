#include <iostream>  // pimpl2.cpp
#include <memory>
using namespace std;
class Accumulator {
  public:
    Accumulator(double init=0) : p{make_unique<Impl>(init)} {}
    double value();
    Accumulator& operator+=(double v);
    void reset();
  private:
    struct Impl;  // forward declaration
    const unique_ptr<Impl> p;
};

struct Accumulator::Impl {  // in separate .cpp file!!!
    Impl(double v) : val{v} {}
    double val{};
    double value() { return val; }
    void incr(double v) { val += v; }
    void reset() { val = 0; }
};
double Accumulator::value() { return p->value(); }
Accumulator& Accumulator::operator+=(double v) {
        p->incr(v);
        return *this;
}
void Accumulator::reset() { p->reset(); }
int main() {
    Accumulator acc;
    acc += 2;
    acc += 40;
    cout << acc.value() << endl;
}
