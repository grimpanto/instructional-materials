#include <iostream>  // threadlocal.cpp
#include <string>
#include <thread>
#include <mutex>

using namespace std;

thread_local unsigned int cnt{10};
mutex cout_mtx;
 
void cnt_chars(const string& str, const int id) {
    // no race cond, cnt belongs to this thread
    cnt += str.size();
    lock_guard<std::mutex> lock(cout_mtx);
    cout << "t" << id << ": " << cnt << endl;
}

int main() {
    string str{"abcdefghi"};
    thread t1{cnt_chars,
              str.substr(0, str.size() / 2), 1};
    thread t2{cnt_chars,
        str.substr(str.size() / 2, str.size()), 2};
    {
        std::lock_guard<std::mutex> lock(cout_mtx);
        std::cout << "main: " << cnt << endl;
    }
    t1.join();  t2.join();
}
