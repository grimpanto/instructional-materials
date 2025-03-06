#include <iostream>  // scoped.cpp
#include <thread>
using namespace std;
class scoped_thread {
    thread t;
  public:
    explicit scoped_thread(thread t_)
      : t{move(t_)} {
        if (!t.joinable())
            throw logic_error("Not joinable");
    }
    ~scoped_thread() { t.join(); }
    scoped_thread(scoped_thread const&) = delete;
    scoped_thread& operator=(
      scoped_thread const&) = delete;
};

void g() {
    this_thread::sleep_for(chrono::seconds(1));
}

int inverse(int x) {
    if (x == 0)
        throw logic_error("div by zero");
    else
       return 1 / x; }

void f() {  // may throw an exception
    thread t{g};
    scoped_thread st{move(t)};//dont do it this way!
    cout << t.joinable() << endl;  // -> 0
    cout << inverse(0) << endl;
}
// main() like before

int main() {
    try {
        f();
    } catch (...) {
        // ignore
    }
}
