#include <iostream>  // destructor4.cpp
using namespace std;
struct Person {
    ~Person() noexcept(false) { throw "error"; }
};
int main() {
    try {
        Person p;
    } catch (...) {
        cout << "caught" << endl;
    }
    cout << "the end" << endl;
}
