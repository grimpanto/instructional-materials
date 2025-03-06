#include <iostream>  // conv3.cpp
using namespace std;

int main() {
    int i{};
    i = 3.5;
    cout << i << endl;  // ok, it's expected
    char c;
    c = 128;  // undef behaviour if 8bits signed
    cout << static_cast<int>(c) << endl;  // explicit
}
