#include <iostream>  // virtualcons.cpp
using namespace std;
struct Person {
    virtual Person* clone() const=0;
    virtual Person* create() const=0;
    virtual ~Person()=default;
};
struct Teacher : public Person {
    Teacher* clone() const { return new Teacher{*this}; }
    Teacher* create() const { return new Teacher{}; }
};
int main() {
    Teacher t;
    Person& p{t};
    Person* pp{p.clone()};
    delete pp;
    pp = p.create();
    delete pp;
}
