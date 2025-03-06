#include <iostream>  // calc.cpp
using namespace std;

int main() {
    int num1; int num2; char op;

    cout << "First number: ";   cin >> num1;
    cout << "Operator [+,-,*,/]: ";  cin >> op;
    cout << "Second number: ";  cin >> num2;

    if (op == '+') cout << num1 + num2 << endl;
    else if (op == '-') cout << num1-num2 << endl;
    else if (op == '*') cout << num1*num2 << endl;
    else if (op == '/') cout << num1/num2 << endl;
}
