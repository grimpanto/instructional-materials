#include <memory>    // weakptr3.cpp
#include <iostream>
using namespace std;

int main() {
    shared_ptr<int> spi{new int{42}};
    weak_ptr<int> wpi{spi};  // init possible
    spi.reset();  // does not own anymore
    try {  // the other way around:
        shared_ptr<int> spi2{wpi};
    } catch(const std::bad_weak_ptr& e) {
        cout << e.what() << '\n';
    }
}
