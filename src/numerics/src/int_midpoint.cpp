#include <iostream>
#include <limits>
#include <type_traits>

using namespace std;

// iff conversion from unsigned to signed preserves bit pattern (C++20!)
template <typename Integer>  // iff int is two-complement
constexpr Integer midpoint(Integer a, Integer b) noexcept {
    using U = make_unsigned_t<Integer>;  // -> type_traits
    return a > b ? a - (U(a) - b) / 2 : a + (U(b) - a) / 2;
}

int main() {
   cout << numeric_limits<int>::min() << endl; // -2147483648
   int a{-2147483640};
   int b{10};
   cout << a + (b - a) / 2 << endl;  // 1073741833
   cout << midpoint(a, b) << endl;  // -1073741815
   a = 11;
   cout << a + (b - a) / 2 << endl;  // 11
   cout << midpoint(a, b) << endl;  // 11
}
