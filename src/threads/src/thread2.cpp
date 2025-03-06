#include <iostream>  // thread2.cpp
#include <thread>
using namespace std;
void f() {
    for (int i{0}; i < 5; ++i) {
        cout << "B";
    }
    cout << flush;
}

int main() {
    thread t{f};
    for (int i{0}; i < 5; ++i) {
        cout << "A";
    }
    cout << flush;
}
