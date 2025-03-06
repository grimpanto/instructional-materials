#include <iostream>  // inheritance4.cpp
using namespace std;
struct Person {
    Person() { print_type(); }
    virtual void print_type() {
        cout << "Person" << endl; }
};
struct Teacher : public Person {
    void print_type() {
        cout << "Teacher" << endl; }
};
int main() {
    Teacher t{};
}
