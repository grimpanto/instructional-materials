#include <iostream>  // func_ptr2.cpp
using namespace std;
int add(int a, int b) { return a + b; }
int mul(int a, int b) { return a * b; }
using func = int (*)(int, int);
using int_list = initializer_list<int>;
int accumulate(int_list list, func f, int init=0) {
    int res{init};
    for (auto elem : list) { res = f(res, elem); }
    return res;
}
int main() {
    cout << accumulate({1, 2, 3, 4}, add) << ' ';
    cout << accumulate({1, 2, 3, 4}, mul, 1);  }
