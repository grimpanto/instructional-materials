#include <iostream>  // mutex.cpp
#include <thread>
#include <mutex>
using namespace std;
int balance{15};
mutex m;
void withdraw(int amount, bool& success) {
    m.lock();
    if (balance >= amount) {
        balance -= amount;
        success = true;
    } else {
        success = false;
    }
    m.unlock();
}

int main() {
    bool success1{};
    bool success2{};
    thread t1{withdraw, 10, ref(success1)};
    thread t2{withdraw, 6, ref(success2)};
    t1.join();
    t2.join();
    cout << balance << ' ' << success1 << ' ';
    cout << success2 << endl;
}
