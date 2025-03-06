#include <iostream>

using namespace std;

struct X {
    int i{42};
};

X f() {
    return X{};
}

X x(X(xx)()) {
    return xx();
}

int main() {
    X();
    X x(X());
    cout << x(f).i << endl;  // -> 42
}
