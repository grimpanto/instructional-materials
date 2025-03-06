#include <iostream>
#include <thread>
using namespace std;

int main() {  // since C++20
    {
        // with 'thread' it would crash...
        // jthread (since C++20) joins by default
        jthread t{[]{ cout << "inside thread" << endl;}};
        cout << "outside thread" << endl;
    }
    cout << "just before end" << endl;
}  // -> scoped thread not needed anymore!
