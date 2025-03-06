#include <iostream>  // string_view.cpp
#include <string_view>
using namespace std;

void f(string_view v) { cout << v << endl; }

int main() {
    char cstr[]{"!hello!"};  string str{"world"};
    string_view cstr_view{cstr + 1, 5};
    string_view str_view{str};

    cout << cstr_view << ' ';
    f(str_view);  // -> hello world
    cout << cstr_view[0] << endl;  // -> h
    // cstr_view[0] = 'x';  immutable
}
