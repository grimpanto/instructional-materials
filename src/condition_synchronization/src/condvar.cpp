#include <iostream>  // condvar.cpp
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>
using namespace std;
using namespace std::literals;

struct IntQueue {
    vector<int> v;  // just for demo purposes
    mutex mtx;
    condition_variable not_empty;
  public:
    void put(int);
    int take();
};

void IntQueue::put(int elem) {
    lock_guard<mutex> lck{mtx};
    v.push_back(elem);
    not_empty.notify_one();
}

int IntQueue::take() {
    unique_lock<mutex> lck{mtx};
    not_empty.wait(lck, [this]{ return v.size();});
    int elem{v.front()};
    v.erase(v.begin());
    return elem;
}

int main() {
    IntQueue s;
    s.put(1);
    s.put(2);
    cout << s.take() << endl;
    cout << s.take() << endl;
    thread t{[&]() { cout << s.take() << endl; }};
    this_thread::sleep_for(3s);
    s.put(3);
    t.join();
}
