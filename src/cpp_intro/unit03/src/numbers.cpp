#include <iostream>  // numbers.cpp
using namespace std;
int main() {
    cout << 123'456'789 << endl;
    cout << hex << 0xFF << endl;
    cout << 0777 << ' ' << oct << 0777 << endl;
    cout << showbase << hex << 0xCAFE << endl;
    cout << dec << 0xff << endl;
}
