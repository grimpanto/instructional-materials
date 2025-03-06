#include <iostream>  // structs4.cpp
using namespace std;

struct Counter {
    inline static int cnt;
    // implicitly inline:
    constexpr static double pi{3.1415};
};

// Neither definition of cnt nor pi!

int main() {
    cout << ++Counter::cnt << endl;
    cout << Counter::pi << endl;
}
