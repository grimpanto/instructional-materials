#include <iostream>  // scope.cpp
using namespace std;
int x;  // global

int main() {
    cout << x << endl;  // 0
    int x;  // local (global x shadowed)
    x = 1;  // local x
    {
        int x=x;  // de facto uninitialized!
        cout << x << endl;  // e.g.: -1081928100
        x = 2;
    }
    x = 3;  ::x = 1;
    cout << x << " " << ::x << endl;  // 3 1
}
