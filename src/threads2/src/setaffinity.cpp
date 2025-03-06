#include <pthread.h>

#include <iostream>  // setaffinity.cpp
#include <vector>
#include <thread>
#include <mutex>
#include <sched.h>  //

using namespace std;
using namespace std::literals;

int main(int argc, const char** argv) {
    constexpr unsigned num_threads = 4;
    mutex mtx;
    vector<thread> threads(num_threads);
    for (unsigned i{}; i < num_threads; ++i) {
        threads[i] = thread([&mtx, i] {
          this_thread::sleep_for(20ms);
          while (true) {
            {
                lock_guard<mutex> iolock(mtx);
                cout << "Thread #" << i
                     << ": on CPU "
                     << sched_getcpu() << "\n";
            }
            this_thread::sleep_for(900ms);
          }});

// cpu_set_t represents a set of CPUs.
        // Clear it and mark only CPU i as set.
        cpu_set_t cpuset;
        CPU_ZERO(&cpuset);
        CPU_SET(i, &cpuset);
        int rc = pthread_setaffinity_np(
            threads[i].native_handle(),
            sizeof(cpu_set_t), &cpuset);
        if (rc != 0) {
          cerr <<
            "Error calling pthread_setaffinity_np: "
            << rc << "\n";
        }
    }
    for (auto& t : threads) t.join();
}
