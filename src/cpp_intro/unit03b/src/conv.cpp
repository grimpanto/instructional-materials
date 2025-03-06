#include <iostream>  // conv.cpp
using namespace std;

int main() {
    char a{'0'};
    char b{'0'};  // ASCII decimal: 48
    cout << a << ' ' << sizeof(a) << endl;
    cout << a + b << ' ' << sizeof(a + b) << endl;
}
