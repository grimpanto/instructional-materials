// greetme3.cpp
#include <iostream>
using namespace std;

int main() {
    string name;
    cout << "Your name: ";
    getline(cin, name);  // reads a whole line...
    cout << "Pleased to meet you, " << name
         << "!" << endl;
}
