#include <iostream>  // signal.cpp
#include <unistd.h>
#include <csignal>
using namespace std;
int pid;

void signal_handler(int signal) {
    cout << "ignoring signal!" << endl;
}

int main() {
    signal(SIGTERM, signal_handler);
    auto i=3;

while (i) {
        cout << i * 5 << " seconds left..." << endl;
        sleep(5);  // will be interrupted by signal
        --i;  }
    cout << "terminating myself" << endl;
}
