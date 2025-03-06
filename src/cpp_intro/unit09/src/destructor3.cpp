#include <iostream>  // destructor3.cpp
using namespace std;
struct Person {
    ~Person() noexcept(false) { throw "error"; }
};
int main() {
    { 
        Person p;
    }
    cout << "the end" << endl;
}
