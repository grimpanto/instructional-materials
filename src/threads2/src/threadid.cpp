#include <iostream>  // threadid.cpp
#include <thread>
using namespace std;
using namespace std::literals;
int main() {
    thread t{[]() { this_thread::sleep_for(1s); }};
    // type std::thread::id
    // comparable (<,<=,==,...) & storable in map
    cout << this_thread::get_id() << ' ';
    cout << t.get_id() << endl;
    t.join();
    thread t2;  // no hw thread associated
    cout << t2.get_id() << endl; }
