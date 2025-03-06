#include <complex>  // init5.cpp
#include <vector>
using namespace std;

int main() {
    int a[]{1, 2, 3};  // array-initializer
    struct S {
        int i;
        string s;
    };
    S s{1, "hello"};  // struct-initializer
    complex<double> z{0, 1};  // use constructor
    vector<int> v{1, 2, 3};  // list-initializer
}
