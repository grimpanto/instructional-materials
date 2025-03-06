#include <iostream>  // zombie2.cpp
#include <unistd.h>
#include <cstdlib>
#include <csignal>  // signal
#include <sys/wait.h>
using namespace std;
pid_t pid;

void signal_handler(int signal) {
    int status;
    sleep(10);
    waitpid(pid, &status, 0);  // auch nullptr möglich
    cout << "child's end awaited" << endl;
}

int main() {
    signal(SIGCHLD, signal_handler);
    pid = fork();  // starts just one child
    if (pid == 0) { quick_exit(EXIT_SUCCESS); }
    cout << "child: " << pid << endl;
    sleep(60);
}
