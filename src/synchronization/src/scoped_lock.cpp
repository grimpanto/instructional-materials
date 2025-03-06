#include <iostream>  // scoped_lock.cpp
#include <thread>
#include <mutex>
using namespace std;
int main() {
    mutex m1{};  mutex m2{};
    thread t1{[&]() {
          scoped_lock sl(m1, m2);
          /* ... */ }};
    thread t2{[&]() {
          scoped_lock sl(m1, m2);
          /* ... */ }};
    t1.join();  t2.join();
}
