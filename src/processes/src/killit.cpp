#include <iostream>  // killit.cpp
#include <csignal>
using namespace std;
int pid;

int main() {
    int pid;
    cout << "pid: ";
    cin >> pid;
    // use 'raise' for sending signals to
    // the current running process, otherwise
    // use 'kill'. Anyway, it's easier to
    // remember just one system call
    kill(pid, SIGKILL);
}
