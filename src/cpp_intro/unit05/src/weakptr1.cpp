#include <memory>    // weakptr1.cpp
#include <iostream>
using namespace std;
int main() {
    weak_ptr<int> wpi;
    {
        auto spi{make_shared<int>(1)};
        wpi = spi;
        cout << *wpi.lock() << ' ';  // shared_ptr!
    }
    // cout << *wpi << endl;  // error!
    // * undefined on nullptr:
    // cout << *wpi.lock() << endl;  // segfault!
    cout << wpi.lock().get() << endl;  // nullptr!
}
