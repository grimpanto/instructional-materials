#include <iostream>  // detach2.cpp
#include <thread>
using namespace std;
using namespace std::literals;
void f() {
    for (int i{0}; i < 5; ++i) {
        cout << "B";
        this_thread::sleep_for(10ms);
    }
}
int main() {
    thread t{f};
    t.detach();
    this_thread::sleep_for(20ms);
}
