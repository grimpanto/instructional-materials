// hello3.cpp
#include <iostream>

int main() {
    // now, std is only available inside main
    using namespace std;
    // \n ... plattform independent new line
    // preferred because of performance
    //   but be aware of flushing...
    cout << "Hello, World!\n" << flush;
}
