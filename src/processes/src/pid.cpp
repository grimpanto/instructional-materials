#include <iostream>  // pid.cpp
// not part of standard C; part of POSIX.1
// therefore it is not named: <cunistd>
#include <unistd.h>

using namespace std;

int main() {
    cout << "pid: " << getpid() << endl;
    cout << "ppid: " << getppid() << endl;
    cout << "uid: " << getuid() << endl;
    cout << "euid: " << geteuid() << endl;
}
