#include <iostream>  // refparthread2.cpp
#include <thread>
#include <functional>  // ref
using namespace std;
using namespace literals;

struct Distance {
    double len{};
    ~Distance() { cout << "dstor" << endl; }
};

int main() {
    Distance* pd;
    {
        Distance d{};
        pd = &d;
        auto incrfunc{[](Distance& d) {
            this_thread::sleep_for(1s); ++d.len; }};
        thread t(incrfunc, ref(d)); // be careful!
        t.detach();
    }
    this_thread::sleep_for(2s);
    cout << "trying to access pd->len..." << endl;
}
