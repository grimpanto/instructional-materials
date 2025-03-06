#include <iostream>  // affinity.cpp
#include <vector>
#include <thread>
#include <mutex>
#include <sched.h>  // sched_getcpu()
using namespace std;
using namespace std::literals;

int main(int argc, const char** argv) {
    constexpr unsigned num_threads = 4;
    mutex mtx;
    vector<thread> threads(num_threads);
    for (unsigned i = 0; i < num_threads; ++i) {
        threads[i] = thread([&mtx, i] {
          while (true) {
              {
                  lock_guard<mutex> iolock(mtx);
                  cout<<"Thread #"<<i<<": on CPU "
                    <<sched_getcpu()<<"\n";
              }
              this_thread::sleep_for(900ms);
          } }); }
    for (auto& t : threads) t.join();
}
