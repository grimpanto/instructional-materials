#include <iostream>  // vararginitlist.cpp
using namespace std;
void log(initializer_list<string> messages) {
    for (auto msg : messages) {
        cout << msg << ' ';
    }
}
int main() {
    log({"testing", "warning", "error"});
}
