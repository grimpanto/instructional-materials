#include <iostream>  // inheritance8.cpp
using namespace std;
struct A {
    virtual void foo()=0;
    virtual void bar()=0;
};
struct B : public virtual A {
    void foo() { bar(); }};
struct C : public virtual A {
    void bar() { cout << "bar" << endl; }};
struct D : public B, public C {};
int main() {
    D d;  B& b{d};  C& c{d};
    d.foo();  b.foo();  c.foo();
}
