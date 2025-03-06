#include <iostream>  // func_obj3.cpp
#include <functional>
using namespace std;

struct Adder {
    int operator()(int a, int b) {
        return a + b;
    }
};

int main() {
    Adder adder;
    cout << adder(41, 1) << endl;
}
