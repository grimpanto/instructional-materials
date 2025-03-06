#include <iostream>  // lock.cpp
#include <thread>
#include <mutex>
using namespace std;
int main() {
    mutex m1{};  mutex m2{};
    thread t1{[&]() { lock(m1, m2);  //...
              m1.unlock(); m2.unlock(); }};
    thread t2{[&]() { lock(m1, m2);  //...
              m2.unlock(); m1.unlock(); }};
    t1.join();  t2.join();
}

#include <iostream>  // lock.cpp
#include <thread>
#include <mutex>
using namespace std;
int main() {
    mutex m1{};  mutex m2{};
    thread t1{[&]() { lock(m1, m2);
          lock_guard<mutex> lock1(m1, adopt_lock);
          lock_guard<mutex> lock2(m2, adopt_lock);
          /* ... */ }};
    thread t2{[&]() { lock(m1, m2);
          lock_guard<mutex> lock1(m1, adopt_lock);
          lock_guard<mutex> lock2(m2, adopt_lock);
          /* ... */ }};
    t1.join();  t2.join();
}
