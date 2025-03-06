#include <iostream>  // thread.cpp
#include <thread>
using namespace std;
void f() {
    for (int i=0; i < 5; ++i) {
        cout << "B";
    }
}

int main() {
    thread t{f};   // thread starts HERE
    for (int i{0}; i < 5; ++i) {
        cout << "A";
    }
}
