#include <iostream>

using namespace std;
using ull = unsigned long long;

template <ull n>
struct Factorial {
    static const ull value = n * Factorial<n - 1>::value;
};

template <>
struct Factorial<0> {
    static const ull value = 1;
};

int main() {
    Factorial<0> f0;
    cout << f0.value << endl;
    cout << Factorial<1>::value << endl;
    cout << Factorial<2>::value << endl;
    cout << Factorial<64>::value << endl;
}
