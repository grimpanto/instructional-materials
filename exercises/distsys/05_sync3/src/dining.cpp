// @copyright 2019 Günter Kolousek

#include "philosopher.h"
#include "semaphore.h"

#include <CLI11.hpp>

#include <iostream>
#include <thread>

using namespace std;

int main(int argc, char* argv[]) {
    bool nodeadlock{};
    bool livelock{};

    CLI::App app("Dining philosophers simulation");

    //    size_t size{};
    app.add_flag("-n,--nodeadlock", nodeadlock, "Prevent a deadlock at all");
    app.add_flag("-l,--livelock", livelock, "Simulate a livelock");

    CLI11_PARSE(app, argc, argv);

    mutex prevent;
    Semaphore prevent_sem{4};
    Semaphore* prevent_sem_ptr;

    if (nodeadlock) {
        prevent_sem_ptr = &prevent_sem;
    } else {
        prevent_sem_ptr = nullptr;
    }

    timed_mutex fork1;
    timed_mutex fork2;
    timed_mutex fork3;
    timed_mutex fork4;
    timed_mutex fork5;

    thread p1{Philosopher{1, fork1, fork2, prevent_sem_ptr, livelock}};
    thread p2{Philosopher{2, fork2, fork3, prevent_sem_ptr, livelock}};
    thread p3{Philosopher{3, fork3, fork4, prevent_sem_ptr, livelock}};
    thread p4{Philosopher{4, fork4, fork5, prevent_sem_ptr, livelock}};
    thread p5{Philosopher{5, fork5, fork1, prevent_sem_ptr, livelock}};

    /*
      thread p1{Philosopher{1, fork1, fork2, prevent_sem_ptr, prevent}};
      thread p2{Philosopher{2, fork2, fork3, prevent_sem_ptr, prevent}};
      thread p3{Philosopher{3, fork3, fork4, prevent_sem_ptr, prevent}};
      thread p4{Philosopher{4, fork4, fork5, prevent_sem_ptr, prevent}};
      thread p5{Philosopher{5, fork5, fork1, prevent_sem_ptr, prevent}};
    */

    p1.join();
    p2.join();
    p3.join();
    p4.join();
    p5.join();
}
