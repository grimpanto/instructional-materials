#include <iostream>  // clone2.cpp
#include <unistd.h>
using namespace std;
int main() {
    cout << "just before forking..."<< endl;
    fork();
    cout << "after fork()!" << endl;
}
