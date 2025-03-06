#include <iostream>
#include <thread>

using namespace std;

int main() {
    {
        // with 'thread' it would crash...
        jthread t{[]{ cout << "inside thread" << endl;}};
        cout << "outside thread" << endl;
    }
    cout << "just before end" << endl;
}
