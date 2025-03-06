#include <iostream>  // inheritance2.cpp
using namespace std;
struct Person {
    string doing() { return "nothing"; } };
struct Teacher : public Person {
    string name;
    Teacher(string name) : name{name} {};
    string doing() { return "teaching"; } };
int main() {
    Person p;
    cout << p.doing() << endl;
    Teacher t{"ko"};
    cout << t.doing() << endl;
    Person* pp{&t};
    cout << pp->doing() << endl; }
