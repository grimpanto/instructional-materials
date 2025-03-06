#include <iostream>  // recursive_locking.cpp
#include <thread>
#include <mutex>
using namespace std;
class Counter {
    int data;
    recursive_mutex m;
  public:
    bool zero() {
       lock_guard<recursive_mutex> lock{m};
       return data == 0;
    }
    void incr() {
        lock_guard<recursive_mutex> lock{m};
        ++data;
    }

void decr() {
        lock_guard<recursive_mutex> lock{m};
        if (!zero()) {
            --data;
        }
    }
};

int main() {
    Counter cnt;
    cnt.decr();
}
