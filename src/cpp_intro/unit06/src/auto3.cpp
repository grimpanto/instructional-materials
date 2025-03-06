#include <iostream>  // auto3.cpp
using namespace std;
auto fac(int n) {
    if (n == 0)
        return 1;  // each return: same type!
    else
        return n * fac(n - 1);
}
// do not reverse the logic of if because
// one return with concrete type must be first

int main() {
    cout << "fac(3): " << fac(3) << endl;
}
