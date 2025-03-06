#include <iostream>  // join2.cpp
#include <thread>
using namespace std;
void f() {
    throw logic_error{"something failed..."};
}
int main() {
    thread t{f};
    t.join();
}
