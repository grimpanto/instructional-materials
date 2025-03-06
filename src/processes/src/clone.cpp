#include <iostream>  // clone.cpp
// not part of standard C → *not* <cunistd>
#include <unistd.h>  // fork
using namespace std;
int main() {
    cout << "just before forking...";
    fork();
    cout << "after fork()!" << endl;
}
