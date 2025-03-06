#include <iostream>  // rodata.cpp
using namespace std;
int main() {
    char cstr[4]{"abc"};
    cstr[1] = 'x';
    cout << cstr << endl;
    char* cptr{"abc"};  // -Wno-write-strings
    cptr[1] = 'x';
    cout << cptr << endl;
}
