#include <iostream>  // final.cpp
using namespace std;

class IntCntr final {
  public:
    virtual int incr(int i) final {
        cout << "IntCntr" << endl; return i + 1; }
    virtual ~IntCntr()=default;
};

class LongCntr : public IntCntr {
  public:
    virtual int incr(int i) override {
        cout << "LongCntr" << endl; return i + 1; }
};
int main() {
    LongCntr lcntr{};
    IntCntr& icntr{lcntr};
    icntr.incr(1L);
}
