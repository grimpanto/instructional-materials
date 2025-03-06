#include <iostream>  // join4.cpp
#include <thread>
using namespace std;

void g() {
    this_thread::sleep_for(chrono::seconds(1));
}

int inverse(int x) {
    if (x == 0)
        throw logic_error("div by zero");
    else
       return 1 / x;
}

class thread_guard {  // join3.cpp
    thread& t;
  public:
    explicit thread_guard(thread& t_)
      : t{t_} {}
    ~thread_guard() {
        if (t.joinable()) {
            t.join();
        }
    } };

void f() {  // may throw an exception
    thread t{g};
    thread_guard tg{t};
    cout << inverse(0) << endl;
}

int main() {
    try {
        f();
    } catch (...) {
        // ignore
    }
}
