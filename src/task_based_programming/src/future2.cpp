#include <iostream>  // future2.cpp
#include <future>
using namespace std;
void doit() { cout << "***" << endl;
    this_thread::sleep_for(3s); }
int main() {  // serialize main with other thread
    future<void> other{async(launch::async, doit)};
    cout << "doing something else... " << endl;
    cout << "waiting for other thread... " << endl;
    other.wait();
    cout << "done" << endl; }
