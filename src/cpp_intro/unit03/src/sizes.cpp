#include <iostream>  // sizes.cpp
#include <limits>
using namespace std;
int main() {
    static_assert(sizeof(int) >= 4, "size(int)<4");
    cout << "1: " << sizeof(1) << endl;
    cout << "1L: " << sizeof(1L) << endl;
    cout << "1LL: " << sizeof(1LL) << endl;
    cout << "max. float: " <<
      numeric_limits<float>::max() << endl;
    cout << "max. double: " <<
      numeric_limits<double>::max() << endl;
    cout << "char signed? " <<
      numeric_limits<char>::is_signed << endl;
}
