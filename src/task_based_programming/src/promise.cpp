#include <iostream>  // promise.cpp
#include <thread>
#include <future>
#include <random>
using namespace std;
int main() {
    random_device rd;
    mt19937 gen{rd()};
    uniform_int_distribution<> dis{0, 100};
    promise<int> result;

    thread calc{[&]() {
        this_thread::sleep_for(1s);
        if (dis(gen) > 50)
            result.set_exception(
              make_exception_ptr(logic_error("x")));
        else
            result.set_value(42);
    }};
    cout << result.get_future().get() << endl;
    calc.join();
}
