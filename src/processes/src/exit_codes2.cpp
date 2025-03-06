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
    quick_exit(123);  // <---
} else {
    cout << "waiting for child..." << endl;
    int status;
    waitpid(pid, &status, 0); // 0...options
    if (int s{WIFEXITED(status)}; s)
        cout << "child terminated w/ exit code "
             << WEXITSTATUS(status) << endl;
    else
        cout << "terminated not by exit nor return" << endl;
    exit(EXIT_SUCCESS);
} }
