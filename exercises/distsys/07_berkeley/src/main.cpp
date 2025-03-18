// @copyright 2016 Günter Kolousek

#include "clock.h"
#include "pipe.h"
#include "printutils.h"

#include <CLI11.hpp>

#include <iostream>
#include <thread>
#include <sstream>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <condition_variable>

#include <ctime>
#include <iomanip>

using namespace std;
using namespace literals;

class Channel {
    Pipe<long> pipe1;
    Pipe<long> pipe2;
  public:
    Pipe<long>& get_pipe1() {
        return pipe1;
    }
    Pipe<long>& get_pipe2() {
        return pipe2;
    }
};


class TimeSlave {
    string name;
    Clock clock;
    Channel channel;
  public:
    TimeSlave(string name_) : name{name_}, clock{name} {}
    TimeSlave(string name_, int hours, int minutes, int seconds) : name{name_}, clock{name, hours, minutes, seconds} {}
    void operator()() {
        thread clock_thd{ref(clock)};

        long master;
        channel.get_pipe2() >> master;
        println(name, ": got time", master, "ms");

        channel.get_pipe1() << (clock.to_time() - master);

        long diff;
        channel.get_pipe2() >> diff;

        println(name, ": got change ", diff);

        clock.from_time(clock.to_time() + diff);

        /*
          channel.get_pipe2() >> value;
          println("Slave ", name, " received value: ", value);
          clock.from_time(value + 1000);
          channel.get_pipe1() << value + 1000;
          println("Slave ", name, " sent value: ", value + 1);
        */

        clock_thd.join();
    }
    Channel* get_channel() {
        return &channel;
    }
};

class TimeMaster {
    string name;
    Clock clock;
  public:
    Channel* channel1;
    Channel* channel2;
  public:
    TimeMaster(string name_) : name{name_}, clock{name} {}
    TimeMaster(string name_, int hours, int minutes, int seconds) : name{name_}, clock{name, hours, minutes, seconds} {}
    void operator()() {
        thread clock_thd{ref(clock)};

        long since_epoch{clock.to_time()};

        channel1->get_pipe2() << since_epoch;
        channel2->get_pipe2() << since_epoch;

        long diff_from1;
        channel1->get_pipe1() >> diff_from1;
        long diff_from2;
        channel2->get_pipe1() >> diff_from2;

        println("master: got diff1", diff_from1, "s");
        println("master: got diff2", diff_from2, "s");

        long mean{(diff_from1 + diff_from2) / 3};

        // send diffs to clients
        channel1->get_pipe2() << (mean - diff_from1);
        channel2->get_pipe2() << (mean - diff_from2);

        // set own clock
        clock.from_time(since_epoch + mean);

        /*
          println("sending to channel1");
          channel1->get_pipe2() << clock.to_time();
          println("end sending to channel1");
          println("sending to channel2");
          channel2->get_pipe2() << clock.to_time();
          println("end sending to channel2");

          long value;
          channel1->get_pipe1() >> value;
          println("received from channel1: ", value);
          channel2->get_pipe1() >> value;
          println("received from channel2: ", value);
        */

        //this_thread::sleep_for(500ms);
        channel1->get_pipe2().close();
        channel2->get_pipe2().close();
        clock_thd.join();
    }
    void set_channel1(Channel* channel) {
        channel1 = channel;
    }
    void set_channel2(Channel* channel) {
        channel2 = channel;
    }
};


int main(int argc, char* argv[]) {

    CLI::App app("Simulate the berkeley-algo");

    bool monotone_mode{};
    unsigned long long latency1{};
    unsigned long long latency2{};
    int deviation1{};
    int deviation2{};
    int deviationm{};

    app.add_flag("--monotone", monotone_mode, "set monotone mode");
    app.add_option("--latency1", latency1, "latency to channel 1 (both directions)");
    app.add_option("--latency2", latency2, "latency to channel 1 (both directions)");
    app.add_option("--deviation1", deviation1, "deviation of clock of slave 1");
    app.add_option("--deviation2", deviation2, "deviation of clock of slave 1");
    app.add_option("--deviationm", deviationm, "deviation of clock of master");

    CLI11_PARSE(app, argc, argv);

    TimeSlave slave1{"slave1", 18, 30, 0};
    TimeSlave slave2{"slave2", 18, 50, 0};

    Channel* channel_ptr{slave1.get_channel()};
    channel_ptr->get_pipe1().set_latency(0);
    channel_ptr->get_pipe2().set_latency(0);

    channel_ptr = slave2.get_channel();
    channel_ptr->get_pipe1().set_latency(0);
    channel_ptr->get_pipe2().set_latency(0);

    TimeMaster master{"master", 18, 40, 0};
    master.set_channel1(slave1.get_channel());
    master.set_channel2(slave2.get_channel());
    thread slave1_thd{ref(slave1)};
    thread slave2_thd{ref(slave2)};
    thread master_thd{ref(master)};
    slave1_thd.join();
    slave2_thd.join();
    master_thd.join();
}
