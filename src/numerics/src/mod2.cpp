#include <iostream>
using namespace std;

int mod(int a, int b) { return ((a % b) + b) % b; }

int main() {
    cout << mod(5, 2) << endl;
    cout << mod(-5, 2) << endl;
    cout << mod(5, -2) << endl;
    cout << mod(-5, -2) << endl;
}
