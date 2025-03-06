#include <iostream>  // destructor.cpp
using namespace std;
struct Resource {
    ~Resource() {
        cout << "dtor of Resource" << endl;
    }
};
struct Person {
};
struct Teacher : public Person {
    Resource r;
};
int main() {
    Person* tp{new Teacher{}};
    delete tp;
}
