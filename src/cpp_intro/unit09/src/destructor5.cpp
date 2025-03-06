#include <iostream>  // destructor5.cpp
using namespace std;
struct Person {
    ~Person() noexcept(false) { throw "error"; }
};
struct Team {
    Person p;
    ~Team() noexcept(false) { throw "error2"; }
};
int main() {
    try {
        Team t;
    } catch (...) {}
    cout << "the end" << endl;
}
