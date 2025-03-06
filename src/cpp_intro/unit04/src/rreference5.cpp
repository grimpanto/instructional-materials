#include <iostream>  // rreference5.cpp
#include <utility>
using namespace std;

void swap(string& a, string& b) {
    string tmp{move(a)};  // the same as the cast!
    a = move(b);
    b = move(tmp);
}

int main() {
    string s1{"foo"}; string s2{"bar"};
    swap(s1, s2);
    cout << s1 << " " << s2 << endl;
}
