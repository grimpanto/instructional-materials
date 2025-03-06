#include <initializer_list>
using namespace std;
int main() { // init.cpp
    // direct-list-initialization
    // explicit and non-explicit constructors
    int i1{1};  // recommended!!!
    // copy-list-initialization
    // only non-explicit constructors
    int i2={2};
    int i3=3;  // don't do it!
    int i4(4);  // also: no!
    auto i5{5};  // be careful of "old" compilers
    auto i6={6}; // not the same: see next slide!
    auto i7=7;  // yes but not needed any more
    auto i8(8);  // almost no...
}
