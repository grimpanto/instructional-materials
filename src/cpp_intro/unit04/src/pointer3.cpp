#include <iostream>  // pointer3.cpp
using namespace std;
int main(int argc, char* argv[]) {
    char name[]{"Maxi"};
    char* p{name};  // implicit conversion
    p = name;  p = &name[0];
    cout << *p << endl;
    p = name + 4;
    cout << static_cast<int>(*p) << endl;
    // undefined: arbitrary value or termination
    cout << *(p + 500000) << endl;
}
