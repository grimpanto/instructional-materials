// @copyright 2019 Günter Kolousek

#ifndef SEMAPHORE_H
#define SEMAPHORE_H

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

class Semaphore {
    int cnt{};
    std::mutex mtx;
    std::condition_variable not_null;
  public:
    Semaphore() {}
    Semaphore(int val) : cnt{val} {}
    void release();
    void acquire();
    int available_permits();
};

#endif
