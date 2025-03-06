#include <iostream>  // refparthread.cpp
#include <thread>
#include <functional>  // ref
using namespace std;

int main() {
    int n{};
    auto incrfunc{[](int& n) { ++n; }};
    // use std::ref, otherwise per-value!
    //   generates 'reference_wrapper'
    thread t{incrfunc, ref(n)};
    t.join();
    cout << n << endl; }
