#include <iostream>  // noexcept.cpp
using namespace std;

class A {
  public:
    // ~A() {  terminate called after throwing an instance of 'int'
    ~A() noexcept(false) {
        throw 42;
    }
};

void f() { A a; }

int main() {
    try {
        f();
    } catch (...) {
        cout << "caught" << endl;
    }
}
