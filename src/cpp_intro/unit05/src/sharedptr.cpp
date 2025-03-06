#include <iostream>  // sharedptr.cpp
#include <memory>
using namespace std;

int main() {
    shared_ptr<int> spi{new int{1}};
    cout << spi.use_count() << ' ';
    {
        shared_ptr<int> spi2{spi};
        cout << spi2.use_count() << ' ';
    }
    cout << spi.use_count() << endl;
}
