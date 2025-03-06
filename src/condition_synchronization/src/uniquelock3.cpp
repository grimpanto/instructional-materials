#include <iostream>  // uniquelock3.cpp
#include <thread>
#include <mutex>
using namespace std;
mutex m1{}; mutex m2{};
void f(int i) {
    unique_lock<mutex> ul1{m1, defer_lock};
    unique_lock<mutex> ul2{m2, defer_lock};
    lock(ul1, ul2);
    cout << 'f' << i << endl;
}
int main() {
    mutex m1{}; mutex m2{};
    thread t1{f, 1};  thread t2{f, 2};
    t1.join();  t2.join();
}
