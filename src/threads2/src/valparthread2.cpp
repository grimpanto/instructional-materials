#include <iostream>  // valparthread2.cpp
#include <thread>
using namespace std;
void f() {
    char buffer[1024]{"very long string..."};
    auto outfunc{[](string msg) {
        cout << "lambda " << msg << endl; }};
    thread t{outfunc, buffer};
    t.detach();
}
int main() {
    f();   this_thread::sleep_for(10ms);
}
