#include <iostream>  // polling.cpp
#include <thread>
#include <mutex>
using namespace std;
using namespace std::literals;
bool flag;
mutex mtx;
void wait_for_flag() {
    unique_lock<mutex> lck{mtx};
    while (!flag) {
        lck.unlock();
        this_thread::sleep_for(100ms);
        cout << "*" << flush;
        lck.lock();
    }
}

void set_flag() {
    this_thread::sleep_for(3s);
    lock_guard<mutex> lck{mtx};
    flag = true;
}

int main() {
    thread t1{wait_for_flag};
    set_flag();
    t1.join();
    cout << endl << "done!" << endl;
}
