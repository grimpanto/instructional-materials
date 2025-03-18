// @copyright 2019 Günter Kolousek

#include <iostream>
#include <chrono>
#include <thread>

#include <unistd.h>
#include <csignal>
#include <sys/wait.h>

#include <cerrno>
#include <cstring>
#include <clocale>

using namespace std;

int main() {
    const char* letter_a{getenv("ABA_LETTER_A")};
    if (!letter_a)
        letter_a = "A";
    const char* letter_b{getenv("ABA_LETTER_B")};
    if (!letter_b)
        letter_b = "B";

    auto pid_a = fork();
    if (pid_a == 0) {
        if (execl("charout", "charout", letter_a, nullptr) == -1) {
            cerr << "starting charout failed: ";
            cerr << strerror(errno) << endl;
            exit(1);
        }
    } else {
        auto pid_b = fork();
        if (pid_b == 0) {
            if (execl("charout", "charout", letter_b, nullptr) == -1) {
                cerr << "starting charout failed: ";
                cerr << strerror(errno) << endl;
                exit(1);
            }
        }
        cout << "waiting for 3 seconds" << endl;
        sleep(3);
        cout << endl << "killing both subprocesses with pids ";
        cout << pid_a << " and " << pid_b << endl;
        kill(pid_a, SIGKILL);
        kill(pid_b, SIGKILL);
        cout << "waiting for both subprocesses to be dead" << endl;
        int status;
        waitpid(pid_a, &status, 0);
        cout << "subprocess " << pid_a << " exited with "
             << WEXITSTATUS(status) << endl;
        waitpid(pid_b, &status, 0);
        cout << "subprocess " << pid_b << " exited with "
             << WEXITSTATUS(status) << endl;
        sleep(10);
    }
}
