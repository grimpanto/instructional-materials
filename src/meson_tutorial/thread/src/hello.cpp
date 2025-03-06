
#include <iostream>
#include <thread>

using namespace std;

int main() {
    thread t{[]{ cout << "Hello"; }};
    t.join();
    cout << " world!" << endl;
}
