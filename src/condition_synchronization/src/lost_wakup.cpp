#include <iostream>
#include <mutex>
#include <condition_variable>
#include <thread>

using namespace std;

mutex mtx;
condition_variable data_ready;

void waiting_for_work(){
    cout << "waiting..." << endl;
    unique_lock<mutex> lck(mtx);
    data_ready.wait(lck);  // 1
    cout << "running " << endl;
}

void set_data_ready(){
    cout << "data prepared!" << endl;
    data_ready.notify_one();  // 2
}

int main() {
    thread t1{set_data_ready};
    thread t2{waiting_for_work};
    t1.join();
    t2.join();
}
