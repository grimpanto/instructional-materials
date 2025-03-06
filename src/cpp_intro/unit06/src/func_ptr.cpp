#include <iostream>  // func_ptr.cpp
using namespace std;
int add(int a, int b) {
    return a + b;
}
int mul(int a, int b) {
    return a * b;
}
int main() {
    int (*f)(int, int);
    f = add; cout << f(3, 2) << ' ';
    f = mul; cout << f(3, 2) << endl;
}
