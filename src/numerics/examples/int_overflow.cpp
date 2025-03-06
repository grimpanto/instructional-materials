#include <iostream>
#include <cstdint>

using namespace std;

int main() {
    // sadly, it's an alias for
    // unsigned char...
    uint8_t i{253};
    cout << +i++ << endl;  // -> 253
    cout << +i++ << endl;  // -> 254
    cout << +i++ << endl;  // -> 255
    cout << +i-- << endl;  // -> 0
    cout << +i << endl;    // -> 255
    // ... so you can't omit the '+'!
    cout << i + i << endl; // -> 510
    i = i + i;
    cout << +i << endl;  // -> 254
}
