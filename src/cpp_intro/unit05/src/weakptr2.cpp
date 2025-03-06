#include <memory>    // weakptr2.cpp
#include <iostream>
using namespace std;
void use_ptr(weak_ptr<int> wpi) {
    cout << *wpi.lock() << ' ';
}
int main() {
    weak_ptr<int> wpi;
    auto spi{make_shared<int>(1)};
    wpi = spi;
    use_ptr(wpi);  // can be copied
    use_ptr(move(wpi));  // but also moved
    // cout << *wpi.lock() << endl;  // segfault!
}
