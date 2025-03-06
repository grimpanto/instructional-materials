#include <iostream>  // variant.cpp
using namespace std;
#include <variant>
int main() {
    variant<int, double, string> v;
    cout << get<int>(v) << endl;  // -> 0
    try {
        cout << get<double>(v) << endl;
    } catch (bad_variant_access& e) {
        cerr << e.what() << endl;  // -> Unexpected index
    }
    v = 42;
    if (holds_alternative<int>(v))
        cout << get<int>(v) << endl;  // 42
    v = 3.1415926;
    cout << get<double>(v) << endl;  // 3.14159
    cout << get<1>(v) << endl;  // 3.14159
    v = "abc";
    cout << get<string>(v) << endl;  // abc
}
