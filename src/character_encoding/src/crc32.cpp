#include <iostream>  // crc32.cpp
#include <bitset>
#define CRC32MASK 0x04C11DB7
using namespace std;

int main() {
    int data[]{1,0,0,0,1,1,0,0};
    uint32_t crc32{};   // Schieberegister

    for (auto bit : data) {
        if (((crc32 >> 31) & 1) != bit)
            crc32 = (crc32 << 1) ^ CRC32MASK;
        else
            crc32 = (crc32 << 1);
    }
    //cout << crc32 << endl;
//    cout << setw(32);
    cout << bitset<32>(crc32) << endl;
}
