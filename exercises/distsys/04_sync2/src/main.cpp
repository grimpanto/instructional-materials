// @copyright 2019 Günter Kolousek

#include "work_packet.h"
#include "work_queue.h"

#include <CLI11.hpp>

#include <iostream>
#include <thread>
#include <mutex>
#include <random>
#include <iomanip>

using namespace std;
using namespace std::literals;

mutex mtx;

void worker(int id, WorkQueue& q) {
    random_device rd;
    mt19937 gen{rd()};
    uniform_int_distribution<> dis{1000, 10000};

    for (;;) {
        {
            lock_guard<mutex> lg{mtx};
            cout << "W" << id << ": Want work packet" << endl;
        }
        WorkPacket p{q.pop()};
        {
            lock_guard<mutex> lg{mtx};
            cout << "W" << id << ": Got work packet " << p.get_id() << endl;
        }
        int d{dis(gen)};
        this_thread::sleep_for(chrono::milliseconds{d});
        {
            lock_guard<mutex> lg{mtx};
            cout << "W" << id << ": Processed work packet " << p.get_id() << " ("
                 << setprecision(2) << d / 1000.0 << "s)" << endl;
        }
    }
}

void usage(string msg="") {
    cerr << "usage: loadsim SIZE" << endl;
    if (msg != "")
        cerr << msg << endl;
    exit(1);
}

int main(int argc, char* argv[]) {
    CLI::App app("Boss and worker simulation");

    size_t size{};
    app.add_option("size", size, "Size of the queue")->required();

    CLI11_PARSE(app, argc, argv);

    WorkQueue q{size};
    thread w1{worker, 1, ref(q)};
    thread w2{worker, 2, ref(q)};
    thread w3{worker, 3, ref(q)};

    random_device rd;
    mt19937 gen{rd()};
    uniform_int_distribution<> dis{0, 1000};

    for (int id{};; ++id) {
        WorkPacket p{id};
        int d{dis(gen)};
        this_thread::sleep_for(chrono::milliseconds{d});
        {
            lock_guard<mutex> lg{mtx};
            cout << "B:  Waiting to submit work packet " << id << endl;
        }
        q.push(p);
        {
            lock_guard<mutex> lg{mtx};
            cout << "B:  Submitted work packet " << id << " (" << setprecision(2) << d / 1000.0 << "s)" << endl;
        }
    }
    w1.join();
    w1.join();
}
