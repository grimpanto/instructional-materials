
#include <iostream>

using namespace std;

int fib(int n) {
    if (n == 1)
        return 1;
    else if (n == 2)
        return 1;
    else
        return fib(n-1) + fib(n-2);
}

int main() {
    cout << "fib(1)" << fib(1) << endl;
    cout << "fib(2)" << fib(2) << endl;
    cout << "fib(3)" << fib(3) << endl;
    cout << "fib(4)" << fib(4) << endl;
    cout << "fib(5)" << fib(5) << endl;
    cout << "fib(6)" << fib(6) << endl;
    cout << "fib(7)" << fib(7) << endl;
    cout << "fib(8)" << fib(8) << endl;
    cout << "fib(9)" << fib(9) << endl;
    cout << "fib(10)" << fib(10) << endl;
    cout << "fib(11)" << fib(11) << endl;
}
