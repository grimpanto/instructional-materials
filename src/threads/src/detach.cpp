#include <iostream>  // detach.cpp
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
  {
    thread t{f};
    // daemon: term by programmers at MIT
    // supernatural being working in the background
    t.detach(); // ... Disk And Execution MONitor
    cout << t.joinable() << endl;
  }  // attn: thread proceeds!
  for (int i{0}; i < 5; ++i) {
      cout << "A";
      this_thread::sleep_for(10ms);
  }
  cout << endl;
}
