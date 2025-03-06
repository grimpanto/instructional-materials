// hello7.cpp
#include <iostream>
#include <chrono>
#include <thread>
using namespace std;
using namespace std::chrono_literals;
int main() {
    // to be called *before* any I/O!
    std::ios_base::sync_with_stdio(false);
    cout << "Hello, World!\n"; // no output at all!
    this_thread::sleep_for(2s); // chrono literal!
    // here the process is terminating normally
    // therefore the buffer will be flushed
    // hence the message will appear
}
