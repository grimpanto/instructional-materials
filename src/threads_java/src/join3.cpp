#include <iostream>  // join3.cpp
#include <thread>
using namespace std;
void g() {
    this_thread::sleep_for(chrono::seconds(1));
}
int inverse(int x) {
    if (x == 0) throw logic_error{"div by zero"};
    else return 1 / x;
}
void f() {  // may throw an exception
    thread t{g};
    cout << inverse(0) << endl;
    t.join();
}
int main() { try { f(); } catch (...) { }}
