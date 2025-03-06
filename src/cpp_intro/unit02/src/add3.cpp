#include <iostream>     // add3.cpp
using namespace std;
int main() {
    int num1; int num2; int res;

    cout << "The first number: ";  cin >> num1;
    cout << "The second number: ";  cin >> num2;
    res = num1 + num2;
    cout << "The result: " << res << endl;

    string rest;  cin >> rest;
    cout << "Remaining string: " << rest << endl;
}
