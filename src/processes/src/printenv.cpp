#include <iostream>  // printenv.cpp
#include <cstdlib>  // getenv
using namespace std;

int main() {
    const char* env_shell{getenv("SHELL")};
    if (env_shell)
        cout << env_shell << endl;
    else
        cout << "SHELL not set" << endl;
}
