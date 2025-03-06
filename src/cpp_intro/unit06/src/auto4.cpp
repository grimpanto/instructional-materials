#include <iostream>  // auto4.cpp
using namespace std;
int x{42};

int& f() {
    return x;
}

int main() {
    auto x1{f()};
    x1++;
    cout << x << ", " << x1 << endl;
    auto& x2{f()};
    x2++;
    cout << x << ", " << x2 << endl;
}
