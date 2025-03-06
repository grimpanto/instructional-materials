#include <iostream>  // directcopy.cpp
using namespace std;

int main() {
    int x1={0};  // copy-initialization
    int x2{0};  // direct-initialization
    auto x3={0};  // initializer_list<int>
    auto x4{0};  // int, since C++17
                 // recommended since C++14:
    cout << x1 << endl;
    cout << x2 << endl;
    //cout << x3 << endl;  // does not compile!
    cout << x4 << endl;
}
