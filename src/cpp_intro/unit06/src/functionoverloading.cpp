#include <iostream>  // functionoverloading.cpp
using namespace std;
void say(char c) {
    cout << c << "! ";
}
void say(const char* str) {
    cout << str << "!! ";
}
void say(string str) {
    cout << str << "!!! ";
}
int main() {
    say('x'); say("World"); say(string{"Bob"});
}
