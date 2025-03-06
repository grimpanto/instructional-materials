#include <iostream>  // lambdathread.cpp
#include <thread>
using namespace std;

int main() {
    thread t{[]() {
             cout << "lambda thread" << endl; }};
    cout << "main thread" << endl;
    t.join();
}
