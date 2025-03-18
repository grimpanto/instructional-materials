// @copyright 2019 Günter Kolousek

#include "semaphore_.h"

#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

void Semaphore::release() {
    { lock_guard<mutex> lg{mtx};
        ++cnt;
    }
    not_null.notify_one();
}

void Semaphore::acquire() {
    unique_lock<mutex> lck{mtx};
    not_null.wait(lck, [this]() { return cnt; });
    --cnt;
}

int Semaphore::available_permits() {
    lock_guard<mutex> lck{mtx};
    return cnt;
}
