#include <iostream>  // rreference3.cpp
using namespace std;

void swap(string& a, string& b) {
    string tmp{a};
    a = b;
    b = tmp;
}

int main() {
    string s1{"foo"}; string s2{"bar"};
    swap(s1, s2);
    cout << s1 << " " << s2 << endl;
}
