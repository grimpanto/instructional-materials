#include <iostream>  // nonrecursive_locking.cpp
#include <thread>
#include <mutex>

using namespace std;

class Counter {
    int data;
    mutex m;
  public:
    bool zero() {
       lock_guard<mutex> lock{m};
       return data == 0;
    }

void incr() {
        lock_guard<mutex> lock{m};
        ++data;
    }
    void decr() {
        lock_guard<mutex> lock{m};
        if (!zero()) { --data; }
    }
};
int main() {
    Counter cnt;
    cnt.decr();
}
