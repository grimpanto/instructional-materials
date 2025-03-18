// @copyright 2019 Günter Kolousek

#include "account.h"

#include <thread>
#include <mutex>

using namespace std;
using namespace std::literals;

void Account::deposit(int amount) {
    unique_lock<mutex> lock{mtx};
    balance += amount;

    /*
    int tmp{balance};
    std::this_thread::sleep_for(10ms);
    balance = tmp + amount;
    */
}


bool Account::withdraw(int amount) {
    lock_guard lock{mtx};
    if (balance >= amount) {
        this_thread::yield();  // Punkt 3
        balance -= amount;
        return true;
    } else {
        return false;
    }
}


int Account::get_balance() {
    mtx.lock();
    return balance;
    mtx.unlock();
}
