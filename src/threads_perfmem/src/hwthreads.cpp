#include <iostream>  // hwthreads.cpp
#include <thread>
using namespace std;
int main() {
    int hw_threads{thread::hardware_concurrency()};
    if (hw_threads) {
        cout << hw_threads << endl;
    } else {
        cout << "no info available" << endl; }}
