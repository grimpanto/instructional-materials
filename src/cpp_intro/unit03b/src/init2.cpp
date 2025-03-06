#include <initializer_list>
class X {};  // init2.cpp

int main() {
    // int i1{1.5};  // compile error: narrowing...
    // int i2={2.5};  // compile error...
    int i3=3.5;  // i3 == 3 → narrowing
    int i4(4.5);  // i4 == 4
    int i5();  // function declaration!!
    X x(X());  // ditto!
}

#include <iostream>
#include <mutex>
#include <typeinfo>
using namespace std;

mutex mtx;
int main() {
  cout << typeid(mtx).name() << endl;  // -> St5mutex
  {
    // new unique_lock named mtx
    unique_lock<mutex>(mtx);  // -> St11unique_lockISt5mutexE
    cout << typeid(mtx).name() << endl;
    // using mtx as mutex will appear the bug
  }
  {
    // temp object initialized with mtx!
    unique_lock<mutex>{mtx};  // -> St5mutex
    cout << typeid(mtx).name() << endl;
    // using mtx as unique_lock will appear the bug
  } }
