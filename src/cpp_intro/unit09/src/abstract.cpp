#include <iostream>  // abstract.cpp
using namespace std;

class Shape {  // abstract class!
  public:
    virtual string print()=0;  // pure virtual (abstract)!
    virtual ~Shape()=default;
};
class Circle : public Shape {
  public:
    string print() override {
        return "I am a circle";
    }
};
int main() {
    Shape* ptr{new Circle};
    cout << ptr->print() << endl;
}
