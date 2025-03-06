#include <iostream>  // teststack.cpp
#include <thread>
#include "stack.h"
using namespace std;

void reader(ThreadsafeStack<int>& s) {
    int i;
    while (true) {
        this_thread::sleep_for(500ms);
        //s.pop(i);    // per reference
        i = *s.pop();  // using shared pointer
        cout << i << endl;
    }
}

void writer(ThreadsafeStack<int>& s) {
    int i{};
    while (true) {
        s.push(i);
        ++i;
        this_thread::sleep_for(500ms);
    } }
    
int main() {
    ThreadsafeStack<int> s;
    thread r{reader, ref(s)};
    thread w{writer, ref(s)};
    r.join();
    w.join();  }
