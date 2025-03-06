int main() {
#include <iostream>  // join.cpp
#include <thread>
using namespace std;
void f() {
    for (int i{0}; i < 5; ++i) {
        cout << "B";
        this_thread::sleep_for(chrono::milliseconds(10));
    }
}
return 0;
}

int main() {
    thread t{f};
    cout << t.joinable() << endl;
    for (int i{0}; i < 5; ++i) {
        cout << "A";
        this_thread::sleep_for(
          chrono::milliseconds(10));
    }
    cout << endl;
    t.join();
    cout << t.joinable() << endl;
}
