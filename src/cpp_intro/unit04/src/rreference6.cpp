#include <iostream>  // rreference6.cpp
#include <utility>
#include "string.h"
using namespace std;

void printit(String&& msg) {
    cout << "rvalue ref: " << msg.s << endl;
}

void printit(const String& msg) {
    cout << "const lvalue ref: " << msg.s << endl;
}

int main() {
    const String s{"abc"};
    printit(move(s));
}
