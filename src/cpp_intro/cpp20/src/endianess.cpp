#include <iostream>
#include <string_view>
#include <bit>

using namespace std;

int main() {
    if constexpr (endian::native == endian::big) {
        cout << "big-endian" << '\n';
    } else { // otherwise endian::little
        cout << "little-endian"  << '\n';  // -> little-endian
    }
}
