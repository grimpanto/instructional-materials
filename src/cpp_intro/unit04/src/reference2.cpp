#include <iostream>  // reference2.cpp
#include <string>
using namespace std;
int main() {
    int* q{new int{1}};
    // int& r1{0};  // error: no lvalue
    // int& r2{q};  // error: wrong type
    {
        const char& r{65};
        cout << r << endl;
    }
}
