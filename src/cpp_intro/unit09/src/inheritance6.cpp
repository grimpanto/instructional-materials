#include <iostream>  // inheritance6.cpp
using namespace std;
struct A { int a;
    virtual void print(string msg) { cout << msg << ' '; }};
struct B : public A { int b; };
struct C : public A { int c; };
struct D : public B, public C {};  // -> dreaded diamond
int main() {
    D d;
    // d.print("Hi");  // error: mehrdeutig!
    d.B::print("Hi");
    // cout << d.a << endl;  // error: mehrdeutig!
    d.B::a = 1;    d.C::a = 2;
    cout << d.B::a << ' ' << d.C::a << endl;
    D* pd{new D};
    // cout << pd << ", " << static_cast<A*>(pd) << endl;
    //   error: mehrdeutig
}
