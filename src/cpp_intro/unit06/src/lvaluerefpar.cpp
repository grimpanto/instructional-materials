#include <iostream>  // lvaluerefpar.cpp
using namespace std;
void incr(int& counter) {
    ++counter;
}

int main() {
    int counter{};
    incr(counter);
    cout << counter << endl;
    // incr(2);  // error
}
