#include <iostream>  // thread2.cpp
#include <thread>
using namespace std;
void f() {
    for (int i{0}; i < 5; ++i) {
        cout << "B";
        this_thread::sleep_for(chrono::milliseconds(10));
    }
}

int main() {
    thread t{f};
    for (int i{0}; i < 5; ++i) {
        cout << "A";
        this_thread::sleep_for(chrono::milliseconds(10));
    }
    cout << flush;
}
