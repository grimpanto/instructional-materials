// @copyright 2019 Günter Kolousek

#include "timeutils.h"

#include <string>
#include <chrono>
#include <tuple>
#include <thread>
#include <mutex>

using namespace std::literals;

class Clock {
    std::string name;
    std::chrono::time_point<std::chrono::system_clock> curr_time{std::chrono::system_clock::now()};
    std::mutex mtx;
    int deviation;
  public:
    Clock(std::string name, int deviation=0) : name{name}, deviation{deviation} {}
    Clock(std::string name, int hours, int minutes, int seconds, int deviation=0);
    void operator()();
    void set_time(int hours_, int minutes_, int seconds_);
    std::tuple<int, int, int> get_time();
    long to_time();
    void from_time(long);
};
