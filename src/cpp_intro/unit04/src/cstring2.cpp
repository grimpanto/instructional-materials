#include <iostream>  // cstring2.cpp
using namespace std;
int main() {
    char cstr[10]{'a', 'b', 'c'};
    cstr[5] = 'e';
    cout << cstr[0] << ' '
         << static_cast<int>(cstr[3]) << ' '
         << static_cast<int>(cstr[4]) << ' '
         << cstr[5] << ' '
         << static_cast<int>(cstr[6]) << endl;
}
