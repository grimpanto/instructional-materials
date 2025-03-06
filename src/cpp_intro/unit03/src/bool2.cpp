#include <iostream>  // bool2.cpp
using namespace std;
int main() {
    bool b1=42;  // b1 == true !!
    //bool b2{42};  // Fehler!

    int i=3;
    while (i) {
        cout << i << ' ';  // 3 2 1
        i--;
    }
}
