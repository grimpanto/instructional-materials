#include <iostream>  // cstring.cpp
using namespace std;
int main() {
    const char cstr[4]{"abc"};
    // also possible: const char cstr[]{"abc"};
    cout << cstr[0] << ' '
         << static_cast<int>(cstr[3]) << endl;
}
