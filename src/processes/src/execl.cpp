#include <iostream>  // execl.cpp
#include <unistd.h>  // execl
using namespace std;

int main() {
    // path of the executable
    // name which will be used in process table
    // 0-terminated list of arguments
    execl("/usr/bin/date", "date",
          "--iso-8601", nullptr);
}
