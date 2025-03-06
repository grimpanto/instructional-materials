#include <iostream>  // rreference7.cpp
#include <utility>
#include "string.h"
using namespace std;

void printit(String&& msg) {
    cout << "rvalue ref: " << msg.s << endl;
}

void printit(String msg) {
    cout << "copy: " << msg.s << endl;
}

int main() {
    const String s{"abc"};
    printit(move(s));
}
