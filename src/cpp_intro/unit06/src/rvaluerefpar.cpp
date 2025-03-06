#include <iostream>  // rvaluerefpar.cpp
using namespace std;
void incr(int&& counter) {
    ++counter;
}
void incr2(const int& counter) {
    // ++counter;  // error
}
int main() {
    int counter{};
    // incr(counter);  // error
    incr(2);  // does not make sense!
    incr2(2);  // does not make sense!
}
