#include <iostream>  // functionoverloading2.cpp
using namespace std;
void say(int i) {  // promotion
    cout << i << "! ";
}
void say(string str) {  // user-defined
    cout << str << "!!! ";
}
int main() {
    say('x'); say("World"); say(string{"Bob"});
}

#include <iostream>  // functionoverloading2.cpp
using namespace std;
void say(long long ll) {  // conversion
    cout << ll << "!! ";
}
void say(string str) {
    cout << str << "!!! ";
}
int main() {
    say(112); say("World"); say(string{"Bob"});
}
