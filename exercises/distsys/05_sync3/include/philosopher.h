// @copyright 2019 Günter Kolousek

#ifndef PHILOSOPHER_H
#define PHILOSOPHER_H

#include <mutex>

#include "semaphore_.h"

class Philosopher {
    int id;
    std::timed_mutex& left;
    std::timed_mutex& right;
    // std::mutex& prevent;  // only necessary iff we have to guarantee that
    // the counter is in sync with the taken forks...
    Semaphore* prevent_sem_ptr;
    bool livelock;
  public:
    /*
      Philosopher(int id_, std::mutex& left_, std::mutex& right_, Semaphore* prev_sem_ptr_)
      : id{id_}, left{left_}, right{right_}, prev_sem_ptr{prev_sem_ptr_} {}
    */

    Philosopher(int id_, std::timed_mutex& left_, std::timed_mutex& right_, Semaphore* prevent_sem_ptr_, bool livelock_
    /*, std::mutex& prevent_ */)
    : id{id_}, left{left_}, right{right_}, prevent_sem_ptr{prevent_sem_ptr_}, livelock{livelock_} /*, prevent{prevent_}*/ {}

    void operator()();
};

#endif
