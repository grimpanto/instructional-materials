#include <iostream>  // sort.cpp
using namespace std;
// argc ... number of arguments
// argv ... array of "char*"
// char* ... char pointer
int main(int argc, char* argv[]) {
    for (int i{0}; i < argc; ++i) {
        cout << argv[i] << endl;
    }
}
