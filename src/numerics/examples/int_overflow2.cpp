#include <iostream>
#include <cstdint>

using namespace std;

int main() {
    uint8_t i{90};
    uint8_t res;
    res = i * i;
    cout << +res << endl;  // -> 164

    uint16_t tmp;
    tmp = i * i;
    // erkennen und auf max setzen
    res = (tmp < 255) ? tmp : 255;
    cout << +res << endl;

    tmp = i * 2;
    res = (tmp < 255) ? tmp : 255;
    cout << +res << endl;
}
