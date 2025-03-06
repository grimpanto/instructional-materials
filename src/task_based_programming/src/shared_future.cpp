#include <iostream>  // shared_future.cpp
#include <future>
using namespace std;
int calc_it() { this_thread::sleep_for(1s);
    return 42; }
void use_it(shared_future<int> f) {
    cout << f.get() << endl; }
int main() {  // serialize main with other thread
    auto other{shared_future<int>{async(
        launch::async, calc_it)}};
    // also: other = async(...).share()
    thread use_it_trd{use_it, other};  // -> 42
    thread use_it2_trd{use_it, other};  // -> 42
    cout << "doing something else... " << endl;
    use_it_trd.join();
    use_it2_trd.join();  }
