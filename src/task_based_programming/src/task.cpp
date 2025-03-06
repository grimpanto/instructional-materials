#include <iostream>  // task.cpp
#include <thread>
#include <future>  // packaged_task
#include <deque>
#include <vector>
using namespace std;
int main() {
    deque<packaged_task<int(int, int)>> tasks{};
    for (int i{}; i < 10; ++i)
        tasks.push_back(
          packaged_task<int(int,int)>(
            [](int i, int j) { return i + j; }));

    vector<future<int>> results;

    while (not tasks.empty()) {
        auto t = move(tasks.front());
        tasks.pop_front();
        results.push_back(t.get_future());
        thread thd{move(t), 1, 2};
        thd.detach();
    }

    int res{};
    for (int i{}; i < 10; ++i) {
        res += results[i].get();
    }
    cout << res << endl;  // -> 30
}
