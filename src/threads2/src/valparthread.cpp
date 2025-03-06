#include <iostream>  // valparthread.cpp
#include <thread>
using namespace std;

int main() {
    auto outfunc = [](string const& msg) {
        cout << "lambda " << msg << endl;
    };
    thread t{outfunc,
             "thread"};
    cout << "main thread" << endl;
    t.join();
}
