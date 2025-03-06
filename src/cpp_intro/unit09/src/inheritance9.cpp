#include <iostream>  // inheritance9.cpp
using namespace std;
struct A {
    int a;
    A() : a{42} {}
    A(int a) : a{a} {} };
struct B : public virtual A {
    int b;
    B() : A{0}, b{1} {} };
struct C : public B {
    int c;
    C() : c{2} {} };
int main() {
    C c;
    cout << c.a << ' ' << c.b << ' ' << c.c << endl;
}

#include <iostream>  // inheritance9.cpp
using namespace std;
struct A {
    int a;
    A() : a{42} {}
    A(int a) : a{a} {} };
struct B : public virtual A {
    int b;
    B() : /* A{0}, */ b{1} {} };  // may stay...
struct C : public B {
    int c;
    C() : A{0}, c{2} {} };
int main() {
    C c;
    cout << c.a << ' ' << c.b << ' ' << c.c << endl;
}
