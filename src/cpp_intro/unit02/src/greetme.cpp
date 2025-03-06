// greetme.cpp
#include <iostream>
using namespace std;
int main() {
    // class "string" opposed to C-string literal
    // declared in <string>, but <iostream>...
    string name;  // constructed onto stack
    cout << "Your name: ";
    // global object "std::cin" -> stdin
    // overloaded operator ">>"
    cin >> name;  // flushing cout beforehand
    cout << "Pleased to meet you, " << name << "!" << endl;
}
