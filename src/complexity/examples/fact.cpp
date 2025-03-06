
#include <iostream>

using namespace std;

long long fact(long long n) {
    if (n == 0)
        return 1;
    else
        return n * fact(n - 1);
}

int main() {
    cout << fact(25) << endl;  // -> 7034535277573963776
    cout << fact(26) << endl;  // -> -1569523520172457984
}
