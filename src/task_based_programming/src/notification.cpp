#include <iostream>  // notification.cpp
#include <thread>
#include <future>
using namespace std;
int main() {
    promise<void> go;
    auto go_future = go.get_future();
    thread worker{[&go]() {
        this_thread::sleep_for(1s);
        go.set_value();
    }};
    go_future.wait();
    cout << "finished working" << endl;
    worker.join(); }
