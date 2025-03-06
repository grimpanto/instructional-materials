#include <iostream>  // greetme5.cpp
#include <iomanip>  // quoted
using namespace std;

int main() {
    string name;  cout << "Your name: ";
    // quoted(string&, delim='"', escape='\\')
    // mainly used for processing CSV,...
    cin >> quoted(name);
    cout << "Pleased to meet you, " << name
         << "!" << endl;
    cout << "Quoted representation: "
         << quoted(name) << endl; }
