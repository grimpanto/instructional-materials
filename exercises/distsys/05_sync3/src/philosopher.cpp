// @copyright 2019 Günter Kolousek

#include "philosopher.h"
#include "utils.h"

#include <thread>
#include <chrono>
#include <iostream>
#include <vector>

using namespace std;
using namespace std::literals;

/*
mutex mtx;

void println(initializer_list<string> words) {
lock_guard<mutex> lg{mtx};
for (auto& word : words) {
cout << word;
}
cout << endl;
}
*/

void Philosopher::operator()() {
    string name{"Philosopher " + to_string(id)};
    while (true) {
        // println({name, " is thinking..."});
        println(name, "is thinking...");
        this_thread::sleep_for(1000ms);

        bool got;

        do {
            // println({name, " attempts to get left fork"});
            println(name, "attempts to get left fork");
            if (prevent_sem_ptr) {
                //            lock_guard<mutex> lg{prevent};
                prevent_sem_ptr->acquire();
                left.lock();
            } else
                left.lock();

            // println({name, " got left fork. Now he wants the right one..."});
            println(name, "got left fork. Now he wants the right one...");
            this_thread::sleep_for(5s);

            got = true;
            if (!livelock)
                right.lock();
            else {
                got = right.try_lock_for(3s);
                if (!got) {
                    this_thread::sleep_for(100ms);
                    left.unlock();
                    println(name, "released left fork due to timeout getting the right one!");
                    this_thread::sleep_for(3s);
                }
            }
        } while (!got);

        if (prevent_sem_ptr)
            println("currently", to_string(prevent_sem_ptr->available_permits() + 1),
            "left forks available");

        // println({name, " got right fork. Now he is eating..."});
        println(name, "got right fork. Now he is eating...");
        this_thread::sleep_for(2000ms);

        // println({name, " finished eating"});
        println(name, "finished eating");
        left.unlock();
        // println({name, " released left fork"});
        println(name, "released left fork");

        if (prevent_sem_ptr)
            prevent_sem_ptr->release();

        right.unlock();
        // println({name, " released right fork"});
        println(name, "released right fork");
    }
}
