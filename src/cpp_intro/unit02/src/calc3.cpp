#include <iostream>  // calc3.cpp
using namespace std;
int main() {
    double num1; double num2; char op;
    cout << "First number: ";   cin >> num1;
    cout << "Operator [+,-,*,/]: ";  cin >> op;
    cout << "Second number: ";  cin >> num2;
    switch (op) {
      case '+':
        cout << num1 + num2;
        break;  // otherwise continue with '-'
      case '-': cout << num1 - num2; break;
      case '*': cout << num1 * num2; break;
      case '/': cout << num1 / num2; break;
      default: cout << "invalid operator";
    } }
