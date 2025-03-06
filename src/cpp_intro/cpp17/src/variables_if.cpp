#include <iostream>  // variables_if.cpp
using namespace std;

int foo() {
    return 1;
}

int main() {
    if (int i{foo()}; i != 0) {
        cout << i << endl;
    }
}
