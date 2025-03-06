#include <iostream>  // private_public.cpp
#include <thread>
#include <mutex>
using namespace std;
class Counter {
    int data;
    mutex m;
    bool zero_() {
       return data == 0;
    }
    void incr_() {
        ++data;
    }

void decr_() {
      if (!zero_()) {
          --data;
      }
  }
public:
  bool zero() {
      lock_guard<mutex> lock{m};
      return zero_();
  }
  void incr() {
      lock_guard<mutex> lock{m};
      incr_();
  }

void decr() {
        lock_guard<mutex> lock{m};
        decr_();
    }
};

int main() {
    Counter cnt;
    cnt.decr();
}
