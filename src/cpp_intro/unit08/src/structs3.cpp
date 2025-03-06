#include <iostream>  // structs3.cpp
using namespace std;

// should be inside .h file
struct Counter {
    static int cnt;
};

// should be inside .cpp file
int Counter::cnt{};
// without -> undefined reference to `Counter::cnt'

int main() {
    cout << ++Counter::cnt << endl;
}
