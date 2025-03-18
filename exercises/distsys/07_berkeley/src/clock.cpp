// @copyright 2016 Günter Kolousek

#include "clock.h"
#include "timeutils.h"
#include "printutils.h"

#include <iostream>
#include <thread>
#include <typeinfo>
#include <chrono>

using namespace std;

Clock::Clock(std::string name, int hours, int minutes, int seconds, int deviation)
  : name{name}, deviation{deviation} {
    curr_time = ::set_time(curr_time, hours, minutes, seconds);
}


void Clock::operator()() {
    while (true) {
        this_thread::sleep_for(1000ms);
        {
            lock_guard<mutex> lg{mtx};
            curr_time += (1s + chrono::milliseconds{deviation});
            println(name, ": ", curr_time);
        }
    }
}


void Clock::set_time(int hours_, int minutes_, int seconds_) {
    {
        lock_guard<mutex> lg{mtx};
        curr_time = ::set_time(curr_time, hours_, minutes_, seconds_);
    }
}


tuple<int, int, int> Clock::get_time() {
    {
        lock_guard<mutex> lg{mtx};
        return ::get_time(curr_time);
    }
}


long Clock::to_time() {
    {
        lock_guard<mutex> lg{mtx};
        return chrono::system_clock::to_time_t(curr_time);
    }
}


void Clock::from_time(long time) {
    {
        lock_guard<mutex> lg{mtx};
        curr_time = chrono::system_clock::from_time_t(time);
    }
}
