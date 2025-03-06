#include <iostream>  // override2.cpp
using namespace std;
class IntCntr {
  public:
    virtual int incr(int i) {
        cout << "IntCntr" << endl; return i + 1; }
    virtual ~IntCntr()=default;
};
class LongCntr : public IntCntr {
  public:
    // override only applicable to virtual functions!
    long incr(long l) override {
        cout << "LongCntr" << endl; return l + 1; }
};
int main() {
    LongCntr lcntr{};
    IntCntr& icntr{lcntr};
    icntr.incr(1L);
}
