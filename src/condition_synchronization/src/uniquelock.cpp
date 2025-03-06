#include <iostream>  // uniquelock.cpp
#include <thread>
#include <mutex>
using namespace std;
int main() {
    mutex m{};
    thread t1{[&]() { unique_lock<mutex> ul{m};
          cout << 't' << '1' << endl;
          }};  // lock_guard would be sufficient!
    thread t2{[&]() { unique_lock<mutex> ul{m};
          cout << 't' << '2' << endl;
          }};
    t1.join();  t2.join();
}
