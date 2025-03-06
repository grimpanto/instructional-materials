#include <iostream>  // future.cpp
#include <future>
using namespace std;
double calc_pi() {
    cout << "calculating 10**30 digits of pi..." << endl;
    this_thread::sleep_for(3s);
    return 3.1415926; }
int main() {
    future<double> pi{async(calc_pi)};
    cout << "doing something else... " << endl;
    cout << pi.get() << endl; }
