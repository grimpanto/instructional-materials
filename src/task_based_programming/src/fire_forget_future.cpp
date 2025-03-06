#include <iostream>  // fire_forget_future.cpp
#include <chrono>
#include <future>
#include <thread>
using namespace std;
int main() {
    async(launch::async, [] {
        this_thread::sleep_for(chrono::seconds(2));
        cout << "first thread" << endl;
    });
    async(launch::async, [] {
        this_thread::sleep_for(chrono::seconds(1));  
        cout << "second thread" << endl;
    });
    cout << "main thread" << endl;  
}
