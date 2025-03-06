#include <iostream>  // string_view2.cpp
#include <string_view>
using namespace std;

int main() {
    string str{"hello world"};
    string_view str_view{str};  // no copying!
    string_view str_view2{str_view.substr(0, 5)};
    cout << str_view2 << endl;  // -> hello
    cout << str_view2.find("l") << endl; // -> 2
}
