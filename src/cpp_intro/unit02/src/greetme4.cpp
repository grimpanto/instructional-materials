#include <iostream>  // greetme4.cpp
using namespace std;

int main() {
    string name;  cout << "Your name: ";
    cin >> name;  getline(cin, name);
    cout << "Pleased to meet you, " << name
         << "!" << endl;  }
