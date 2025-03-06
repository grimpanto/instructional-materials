#include <iostream>  // optional.cpp
#include <optional>
using namespace std;
optional<int> result(bool answer) {
    if (answer) return 42;
    else return nullopt;  // not set
}
int main() {  // operator*: unchecked!
    cout << *result(false) << endl;//-> 65535 =>not checked!
    try {  // value() => checked
        cout << result(false).value();
    } catch (bad_optional_access& e) {
        cout << e.what() << endl;  // -> bad optional access
    }
    if (!result(false)) cout << "not set!!!" << endl;
    cout << result(false).value_or(-1) << endl;  // -> -1
    auto answer{result(true)};
    if (answer)  // here we check it!!!
        cout << "answer:" << *answer << endl;  // 42
}
