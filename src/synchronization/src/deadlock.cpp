#include <iostream>  // deadlock.cpp
#include <thread>
#include <mutex>
using namespace std;
int main() {
    mutex m1{};
    mutex m2{};
    thread t1{[&]() { m1.lock(); m2.lock();  //...
                     m1.unlock(); m2.unlock(); }};
    thread t2{[&]() { m2.lock(); m1.lock();  //...
                      m2.unlock(); m1.unlock(); }};
    t1.join();
    t2.join();
}
