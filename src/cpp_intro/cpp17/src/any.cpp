#include <vector>
#include <any>
#include <iostream>  // any.cpp
using namespace std;

int main() {
    cout << boolalpha;
    vector<any> v{true, 2017, string{"abc"}, 3.14};
    cout << "any_cast<bool>v[0]: "
      << any_cast<bool>(v[0]) << endl;  // true
    cout << "any_cast<int>v[0]: "
      << any_cast<int>(v[1]) << endl;  // 2017
    try {
        cout << "any_cast<char>(v[0]: "
          << any_cast<char>(v[0]) << endl;
    } catch (const bad_any_cast& e) {
        cout << e.what() << endl;
        // any_cast<char>(v[0]): bad any_cast
    }
    cout << "v[0].type().name(): "
      << v[0].type().name() << endl;  // b
    cout << "v[1].type().name(): "
      << v[1].type().name() << endl;  // i
}
