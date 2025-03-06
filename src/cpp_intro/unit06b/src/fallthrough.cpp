#include <iostream>  // fallthrough.cpp
using namespace std;
int main() {
    enum class X {A, B, C, D};
    X x{X::A};
    switch (x) {
      case X::A:
        cout << "A" << endl;
        break;
      case X::B:
        cout << "B" << endl;
        [[fallthrough]];
      case X::C:
        // warning: this statement may fall through
        cout << "C" << endl;
      case X::D:
        cout << "D" << endl;
    }
}
