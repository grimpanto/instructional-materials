#include <iostream>  // waitpid.cpp
#include <unistd.h>
#include <cerrno>  // errno
#include <cstdlib>  // exit
#include <sys/wait.h>  // waitpid
using namespace std;
int main() {
    pid_t pid;
    pid = fork();
    if (pid == -1) {
        cerr << "forking failed: " << errno<< endl;
        exit(EXIT_FAILURE);
    }

if (pid == 0) {
        cout << "child process here!" << endl;
        sleep(3);
        quick_exit(EXIT_SUCCESS);
    } else {
        cout << "child pid is " << pid << endl;
        cout << "waiting for child..." << endl;
        int status;
        waitpid(pid, &status, 0); // 0...options
        cout << "child terminated w/ exit code "
             << status << endl;
        exit(EXIT_SUCCESS);
    }
}
