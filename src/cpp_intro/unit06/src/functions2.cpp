#include <iostream>
using namespace std;  // functions2.cpp

double squared(double val) { return val * val; }
void print(string message) { cout << message; }
int one() { return 1; }

int main() {
    print("2^2 - 1 = ");
    cout << squared(2) - one() << endl;
}
