#include <iostream>  // once.cpp
#include <thread>
#include <mutex>

using namespace std;
shared_ptr<int> ptr;
once_flag resource_flag;
void init_resource() {
    ptr.reset(new int{42});
    cout << "ptr reset to " << *ptr << endl;
}

void use_ptr() {
    call_once(resource_flag, init_resource);
    cout << *ptr << endl;
}

int main() {
    thread t1{use_ptr};
    thread t2{use_ptr};
    t1.join(); t2.join();
}
