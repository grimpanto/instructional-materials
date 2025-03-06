#include <iostream>  // structured_bindings3.cpp
using namespace std;
struct User {
    string name;  int age;
};

User get_user() { return User{"maxi", 42}; }

int main() {
    auto [name, age]{get_user()};
    cout << name << ' ' << age << endl;
    // -> maxi 42
}
