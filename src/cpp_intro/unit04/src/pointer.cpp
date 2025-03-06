#include <iostream>  // pointer.cpp
using namespace std;
int main(int argc, char* argv[]) {
    int age{42};
    cout << age << ' ';  // access by name
    int* p{&age};
    // access by pointer:
    cout << p << ' ' << *p << endl;
    p = new int{3};  cout << *p << ' ';
    delete p;  // don't forget → memory leak
    cout << *p << endl;  // dangling pointer!
    //p = nullptr; cout<< *p<< endl;  // segfault!
}
