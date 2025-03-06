#include <iostream>  // zombie.cpp
#include <unistd.h>
#include <cstdlib>
using namespace std;
int main() {
    auto pid{fork()};
    if (pid == 0) { quick_exit(EXIT_SUCCESS); }
    cout << "child: " << pid << endl;
    sleep(60);
}
