#include <iostream>  // rreference4.cpp
using namespace std;

void swap(string& a, string& b) {
    string tmp{static_cast<string&&>(a)};  // move constructor!
    a = static_cast<string&&>(b);  // move assignment!
    b = static_cast<string&&>(tmp);  // move assignment!
}

int main() {
    string s1{"foo"}; string s2{"bar"};
    swap(s1, s2);
    cout << s1 << " " << s2 << endl;
}
