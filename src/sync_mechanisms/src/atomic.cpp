#include <iostream>
#include <thread>
#include <atomic>
using namespace std;
struct AtomicCounter {
  atomic<int> value{};
  void incr(){ ++value; }
  void decr(){ --value; }
  int get(){ return value.load(); } };

int main() {  AtomicCounter c;
  thread t1{[&c](){ c.incr(); cout << c.get(); }};
  thread t2{[&c](){ c.incr(); cout << c.get(); }};
  t1.join();  t2.join(); }
