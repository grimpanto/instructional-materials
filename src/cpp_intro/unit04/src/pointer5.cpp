#include <iostream>  // pointer5.cpp
#include <string>
using namespace std;

struct Person {
    string first_name;  string last_name;
    int year_of_birth;
};

int main() {
    Person* p{new Person{"Max", "Mustermann", 90}};
    cout << (*p).first_name << endl; //parentheses!
    cout << p->last_name << endl;
    delete p;
    p = nullptr;  delete p;  // safe!
}
