#include <iostream>  // rreference2.cpp
using namespace std;
string f() {
    return "f()";
}
int main() {
    // string& res{f()};  // error
    string&& res{f()};
    cout << res << endl;
}
