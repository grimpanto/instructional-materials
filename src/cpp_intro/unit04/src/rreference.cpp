#include <iostream>  // rreference.cpp
using namespace std;
string f() {
    return "f()";
}
int main() {
    // at least one copy possible! (up to C++14)
    string res{f()};
    cout << res << endl;
}
