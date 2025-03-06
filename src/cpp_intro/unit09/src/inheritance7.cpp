#include <iostream>  // inheritance7.cpp
using namespace std;
struct A { int a;
    virtual void print(string msg) { cout << msg << ' '; }};
struct B : public virtual A { int b; };
struct C : public virtual A { int c; };
struct D : public B, public C {};
int main() {
    D d;  d.print("Hi");  d.B::print("Hi");
    cout << d.a << endl;
    d.B::a = 1;    d.C::a = 2;
    cout << d.B::a << ' ' << d.C::a << endl;
    D* pd{new D};
    A* pa{static_cast<A*>(pd)};
    cout << pd << ", " << pa << ", " << (pd == pa) << endl;
}
