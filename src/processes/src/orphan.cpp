#include <iostream>  // orphan.cpp
#include <unistd.h>
#include <cstdlib>
using namespace std;
int main() {
    auto pid = fork();
    if (pid == 0) {
        cout << "parent: " << getppid() << endl;
        sleep(5);
        cout << "parent: " << getppid() << endl;
        quick_exit(EXIT_SUCCESS); }
    sleep(3);
}
