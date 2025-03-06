#include <iostream>  // inheritance5.cpp
using namespace std;
struct Number {
    virtual void print_num(double d) {
        cout << "is double: " << d << endl; }
    virtual void print_num(int i) {
        cout << "is int: " << i << endl; }
};
struct SpecialNumber : public Number {
    void print_num(int i) {
        cout << "is special int: " << i << endl; }
};
int main() {
    SpecialNumber num;
    num.print_num(3.5);
}
