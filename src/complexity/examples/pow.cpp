
#include <iostream>

using namespace std;

double pow0(double x, unsigned int n) {
    double res{(n == 0) ? 1 : x};
    for (unsigned int i{1}; i < n; res *= x, ++i);
    return res;
}


double pow1(double x, unsigned int n) {
    double res{1};
    if (n) {
        res = pow1(x, n / 2);
        res *= res;
        if (n % 2)
            res *= x;
    }
    return res;
}

double pow(double x, unsigned int n) {
    double res{1};
    do {
        if (n & 1) res *= x;
        x *= x;
    } while (n >>= 1);
    return res;
}

int main() {
    cout << pow(5, 0) << endl;
    cout << pow(5, 1) << endl;
    cout << pow(5, 2) << endl;
    cout << pow(5, 3) << endl;
    cout << pow(-5, 0) << endl;
    cout << pow(-5, 1) << endl;
    cout << pow(-5, 2) << endl;
    cout << pow(-5, 3) << endl;

}
