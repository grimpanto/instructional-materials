#include <iostream>  // stack_heap.cpp
using namespace std;
int main() {
    int i;
    int j;
    int k;
    int* p1 = new int;
    int* p2 = new int;
    int* p3 = new int;
    cout << &i << ' ' << &j << ' ' << &k << endl;
    cout<< &*p1<< ' '<< &*p2<< ' '<< &*p3<< endl;
}
