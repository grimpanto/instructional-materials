#include <iostream>  // future_wait_for.cpp
#include <chrono>
#include <future>
#include <thread>
#include <algorithm>  // accumulate
using namespace std;
int accumulate_block(int* data, size_t count) {
    this_thread::sleep_for(3s);
    return accumulate(data, data + count, 0);
}

int main(int argc, const char** argv) {
  vector<int> v{1, 2, 3, 4, 5, 6, 7, 8};
  future<int> acc = std::async(launch::async,
    accumulate_block, v.data(), v.size());
  while (acc.wait_for(chrono::seconds(1)) !=
         future_status::ready) {
      cout << "...still not ready\n";
  }
  cout << "result: " << acc.get() << "\n";
}
