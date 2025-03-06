#include <iostream>  // uniquelock2.cpp
#include <thread>
#include <mutex>
using namespace std;
using namespace std::literals;
void f(unique_lock<mutex> ul) {
    cout<< 'f'<< endl;
    this_thread::yield();  /* "no effect" */ }
int main() {
    mutex m{};
    thread t1{[&]() {
      unique_lock<mutex> ul{m};
      cout << 't' << '1'; f(move(ul));
      this_thread::sleep_for(10ms);
      cout << 't'; this_thread::sleep_for(10ms);
      cout << '1' << endl;  }};

thread t2{[&]() {
      unique_lock<mutex> ul{m};
      cout << 't' << '2'; f(move(ul));
      this_thread::sleep_for(10ms);
      cout << 't'; this_thread::sleep_for(10ms);
      cout << '2' << endl;  }};
    t1.join();
    t2.join();
}
