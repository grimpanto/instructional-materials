#include <iostream>  // rwlock.cpp
#include <shared_mutex>  // since C++14!
#include <thread>
#include <random>
using namespace std;
using namespace std::chrono;
// ATTN: only shared_timed_mutex until C++14!
shared_mutex mtx;

void reader(string name) {
    random_device rd;
    mt19937 gen{rd()};
    uniform_int_distribution<> dis{100, 500};
    while (true) {
        this_thread::sleep_for(
          milliseconds{dis(gen)});
        shared_lock<shared_mutex> sl{mtx};
        cout << name << ": enters" << endl;
        this_thread::sleep_for(milliseconds{100});
        cout << name << ": leaves" << endl;
    }
}

void writer(string name) {
    random_device rd;
    mt19937 gen{rd()};
    uniform_int_distribution<> dis{0, 100};
    while (true) {
        this_thread::sleep_for(
          milliseconds{dis(gen)});
        unique_lock<shared_mutex> ul{mtx};
        cout << name << ": enters" << endl;
        this_thread::sleep_for(milliseconds{1000});
        cout << name << ": leaves" << endl;
    }
}

int main() {
    thread rdr1{reader, "r1"};
    thread rdr2{reader, "r2"};
    thread rdr3{reader, "r3"};
    thread wtr{writer, "w1"};
    rdr1.join();
    rdr2.join();
    rdr3.join();
    wtr.join();
}
